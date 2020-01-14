

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* maxSlidingWindow(int* a, int asz, int k, int* bsz) {
	if (asz == 0) {
		return 0;
	}
	//if (asz == 0) {
	//	*bsz = 0;
	//	int b[0];
	//	return b;
	//}
	if (asz == 1 || k==1) {
		*bsz = asz;
		return a;
	}
	*bsz = asz - k + 1;
	int* b = (int*)malloc((*bsz)*sizeof(int));
	int tidx=0,i=0,j=1,t=0;
	for (i = 1; i < k; ++i) {
		if (a[i] > a[tidx]) {
			tidx = i;
		}
	}
	b[0] = a[tidx];

	for (i = k; i < asz; ++i) {
		if (tidx >= (i-k+1)) {
			if (a[i] > a[tidx]) {
				tidx = i;
			}	
		}
		else {
			tidx = i-k+1;
			for (t = 2; t <= k; ++t) {
				if (a[i-k + t] > a[tidx]) {
					tidx = i -k+ t;
				}
			}
		}
		b[j++] = a[tidx];		
	}
	return b;
}



int main()
{
	//int a[8] = { 1,3,-1,-3,5,3,6,7 };
	int a[3] = {7,2,4};
	int bsz;
	int* b = maxSlidingWindow(a,3,2,&bsz);

	for (int i = 0; i < bsz; ++i) {
		printf("%d ",b[i]);
	}
	printf("\n");
	free(b);


	
	system("pause");

}





