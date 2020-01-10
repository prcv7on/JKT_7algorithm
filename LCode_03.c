

#include <stdio.h>
#include <stdlib.h>


void merge(int* a1, int sz1, int m, int* a2, int sz2, int n) {
	if (sz1 == 0 || sz2 == 0 || n == 0) return;
	int p1 = m - 1;
	int p2 = n - 1;
	int p = m + n - 1;
	while (p1 >= 0 && p2 >= 0) {
		a1[p--] = (a1[p1] < a2[p2]) ? a2[p2--] : a1[p1--];
	}
	while (p1 >= 0) {
		a1[p--] = a1[p1--];
	}
	while (p2 >= 0) {
		a1[p--] = a2[p2--];
	}

}



int main()
{
	//int a1[10] = { 1,3,5,6,8 }; //m=5
	//int a2[3] = {2,4,9};		//n=3
	int a1[2] = {2,0};//m=1
	int a2[1] = {1};//n=1

	//merge(a1,10,5,a2,3,3);
	merge(a1,2,1,a2,1,1);

	for (int i = 0; i < 2; ++i) {
		printf("%d ",a1[i]);
	}

	printf("\n");
	system("pause");

}





