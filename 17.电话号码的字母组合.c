/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// @lc code=end


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int csize(char c) {
    if (c=='7' || c=='9') return 4;
    return 3;
}

char** letterCombinations(char* digits, int* sz) {
    int l=strlen(digits);
    if (!l) return NULL;
    int i,j,k;
    char num[8][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    *sz=1;
    for (i=0;i<l;++i) {
        *sz *= csize(digits[i]);
    }

    char** res = (char**)malloc(*sz * sizeof(char*));
    for (i=0;i<(*sz);++i) {
        res[i]=(char*)malloc((l+1)*sizeof(char));
        res[i][l]='\0';
    }

    k=*sz;
    for (i=0;i<l;++i) {
        k /= csize(digits[i]);
        for (j=0;j<(*sz);++j) {
            res[j][i]=num[digits[i]-'2'][(j/k)%csize(digits[i])];
        }
    }
    return res;
}


int main() {
    char nums[] = "357";
    int sz;
    char** ret=letterCombinations(nums,&sz);

    printf("sz=%d\n",sz);
    for (int i=0;i<sz;++i) {
        printf("%s \n",ret[i]);
    }
    printf("\n");

}
