

#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int sz, int k) {
	if (k%sz == 0 || sz == 1) {
		return;
	}
	k %= sz;

	int i, j;
	for (i = 0, j = sz - k - 1; i < j; ++i, --j) {
		nums[i] ^= nums[j];
		nums[j] ^= nums[i];
		nums[i] ^= nums[j];
	}
	for (i = sz - k, j = sz - 1; i < j; ++i, --j) {
		nums[i] ^= nums[j];
		nums[j] ^= nums[i];
		nums[i] ^= nums[j];
	}
	for (i = 0, j = sz - 1; i < j; ++i, --j) {
		nums[i] ^= nums[j];
		nums[j] ^= nums[i];
		nums[i] ^= nums[j];
	}


}



int main()
{
	int arr[8] = {1,2,3,4,5,6,7,8};
	int k = 3;
	rotate(arr,8,k);

	for (int i = 0; i < 8; ++i) {
		printf("%d ",arr[i]);
	}
	printf("\n");

	system("pause");

}





