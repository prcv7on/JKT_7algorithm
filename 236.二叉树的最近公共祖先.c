/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// @lc code=end



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TN;

bool dfs(TN* root, TN* end, TN** path,int* cnt) {
    path[(*cnt)++]=root;
    if (root == end) {
        return true;
    }
    if (root->left && dfs(root->left, end, path,cnt)) {
        return true;
    }
    
    if (root->right && dfs(root->right, end, path,cnt)) {
        return true;
    }
    --(*cnt);
    return false;
}


TN* lowestCommonAncestor(TN* root, TN* p, TN* q) {
    if (!root || !p || !q) return NULL;
    TN** path1=(TN**)malloc(200*sizeof(TN*));
    TN** path2=(TN**)malloc(200*sizeof(TN*));
    int cnt1=0,cnt2=0;
    dfs(root,p,path1,&cnt1);
    dfs(root,q,path2,&cnt2);
    printf("cnt1=%d\n",cnt1);
    printf("cnt2=%d\n",cnt2);

    for (int i=0;i<cnt1;++i) {
        printf("%d ",path1[i]->val);
    }
    printf("\n");
    for (int i=0;i<cnt2;++i) {
        printf("%d ",path2[i]->val);
    }
    printf("\n");

    int len=(int)fmin(cnt1,cnt2);
    for (int i = 0; i < len; i++) {
        if (path1[i]->val != path2[i]->val) {
            break;
        }
        root = path1[i];
    }
    return root;
}



int main() {
    TN a1,a2,a3,a4,a5,a6,a7,a8,a9;
    a1.val=3;a1.left=&a2; a1.right=&a3;
    a2.val=5;a2.left=&a4; a2.right=&a5;
    a3.val=1;a3.left=&a6; a3.right=&a7;
    a4.val=6;a4.left=NULL;a4.right=NULL;
    a5.val=2;a5.left=&a8; a5.right=&a9;
    a6.val=0;a6.left=NULL;a6.right=NULL;
    a7.val=8;a7.left=NULL;a7.right=NULL;
    a8.val=7;a8.left=NULL;a8.right=NULL;
    a9.val=4;a9.left=NULL;a9.right=NULL;

    TN* b1=lowestCommonAncestor(&a1,&a4,&a9);

    printf("b1->val=%d \n",b1->val);

}
