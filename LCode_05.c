

#include <stdio.h>
#include <stdlib.h>


void moveZeroes(int* nums, int sz) {
	int i=0,j=0;
	for (; i < sz; ++i) {
		if (nums[i] != 0) {
			if (i != j) {
				nums[j] = nums[i];
				nums[i] = 0;
			}
			++j;
		}
	}
}


int main()
{
	int a[10] = {2,1,0,7,9,0,4,0,8,10};
	//int a[2] = {2,1};
	moveZeroes(a,2);

	for (int i = 0; i < 2; ++i) {
		printf("%d ", a[i]);
	}

	printf("\n");
	system("pause");

}





