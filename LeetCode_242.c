

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isAnagram(char* s, char* t) {
	size_t ls = strlen(s);
	size_t lt = strlen(t);
	if (ls != lt)
		return false;
	int arr[27] = { 0 };
	arr[26] = 1;
	size_t i = 0;
	for (; i < ls; ++i) {
		++arr[s[i] - 'a'];
		--arr[t[i] - 'a'];
	}
	i = 0;
	while (arr[i++] == 0);
	return i == 27 ? true : false;
}



int main()
{
	char str1[] = "anagram";
	char str2[] = "nagaram";
	bool b1 = isAnagram(str1,str2);
	printf("true=%d\n", true);
	printf("b1=%d\n",b1);
	
	system("pause");

}





