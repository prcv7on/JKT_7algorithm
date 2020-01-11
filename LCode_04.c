

#include <stdio.h>
#include <stdlib.h>


typedef struct Stu {
	int val;
	int idx;
}St;


int cmp(const St* a, const St* b) {
	return a->val - b->val;
}

int* twoSum(int* nums, int sza, int target, int* szb) {
	int i, j;
	int* p = NULL;
	*szb = 0;
	St* mys = (St*)malloc(sza * sizeof(St));
	for (i = 0; i < sza; ++i) {
		mys[i].val = nums[i];
		mys[i].idx = i;
	}
	qsort(mys, sza, sizeof(St), cmp);

	for (i = 0, j = sza - 1; i < j;) {
		if (mys[i].val + mys[j].val < target)
			++i;
		else if (mys[i].val + mys[j].val > target)
			--j;
		else if (mys[i].val + mys[j].val == target) {
			*szb = 2;
			p = (int*)malloc(2*sizeof(int));
			p[0] = mys[i].idx;
			p[1] = mys[j].idx;
			break;
		}
	}
	free(mys);	

	return p;
}



int main()
{
	int a[10] = {1,3,5,7,2,4,11,8,9,6};
	int b = 19;
	int bsz;
	int* s = twoSum(a,10,b,&bsz);

	for (int i = 0; i < bsz; ++i) {
		printf("%d ",s[i]);
	}	
	free(s);

	//for (int i = 0; i < 10; ++i) {
	//	printf("%d ", mys[i].idx);
	//}
	//printf("\n");
	//for (int i = 0; i < 10; ++i) {
	//	printf("%d ", mys[i].val);
	//}
	//printf("\n");


	//qsort(a,10,sizeof(int),cmp);
	printf("\n");
	system("pause");

}





