/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* a, int asz, int* bsz, int** csz) {
    *bsz = 1<<asz;
    int** res=(int**)malloc(*bsz * sizeof(int*));
    csz[0]=(int*)malloc(*bsz * sizeof(int));
    int i=0,j=0,sz=0;
    for (i=0;i<*bsz;++i) {
        res[i]=(int*)malloc(*bsz * sizeof(int));
        sz=0;
        for (j=0;j<asz;++j) {
            if (i & (1<<j)) {
                res[i][sz++]=a[j];
            }    
        }
        csz[0][i]=sz;
    }
    return res;
}


// @lc code=end


#include <stdio.h>
#include <stdlib.h>

// int S = nums.size();
// int N = 1 << S;
// vector<vector<int> > res;
// for (int i = 0; i < N; ++i) {
//     vector<int> v;
//     for (int j = 0; j < S; ++j)
//         if (i & (1 << j))
//             v.push_back(nums[j]);
//     res.push_back(v);
// }
// return res;

int** subsets(int* a, int asz, int* bsz, int** csz) {
    *bsz = 1<<asz;
    int** res=(int**)malloc(*bsz * sizeof(int*));
    csz[0]=(int*)malloc(*bsz * sizeof(int));
    int i=0,j=0,sz=0;
    for (i=0;i<*bsz;++i) {
        res[i]=(int*)malloc(*bsz * sizeof(int));
        sz=0;
        for (j=0;j<asz;++j) {
            if (i & (1<<j)) {
                res[i][sz++]=a[j];
            }    
        }
        csz[0][i]=sz;
    }
    return res;
}


int main() {
    int nums[3] = {1,2,3};
    int bsz;
    int csz;int* pc=&csz;
    int** ret=subsets(nums,3,&bsz,&pc);

    printf("bsz=%d\n",bsz);
    for (int i=0;i<bsz;++i) {
        for (int j=0;j<pc[i];++j) {
            printf("ret[%d][%d]=%d ",i,j,ret[i][j]);
        }
        printf("\n");
    }


}

