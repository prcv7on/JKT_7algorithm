/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
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


typedef struct TreeNode TN;

int* midorderTraversal(TN* root, int* sz) {
	*sz = 0;
	// if (!root) return 0;
	// if (!root->left && !root->right) {
	// 	*sz = 1;
	// 	return &(root->val);
	// }
	int* ret = (int*)malloc(10000 * sizeof(int));
	TN** stack = (TN**)malloc(10000 * sizeof(TN*));
	int cnt = -1;
	while (root || cnt != -1) {
		while (root) {
			stack[++cnt] = root;
			root = root->left;
		}
		root = stack[cnt--];
		ret[(*sz)++] = root->val;
		root = root->right;
	}
	free(stack);
	return ret;
}

bool isValidBST(TN* root) {
    if (!root || (!root->left && !root->right)) return true;
    int msz=0;
    int* midT=midorderTraversal(root,&msz);
    for (int i=1;i<msz;++i) {
        if (midT[i]<=midT[i-1]) return false;
    }
    return true;
}


// @lc code=end


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TN;

int* midorderTraversal(TN* root, int* sz) {
	*sz = 0;
	// if (!root) return 0;
	// if (!root->left && !root->right) {
	// 	*sz = 1;
	// 	return &(root->val);
	// }
	int* ret = (int*)malloc(90 * sizeof(int));
	TN** stack = (TN**)malloc(90 * sizeof(TN*));
	int cnt = -1;
	while (root || cnt != -1) {
		while (root) {
			stack[++cnt] = root;
			root = root->left;
		}
		root = stack[cnt--];
		ret[(*sz)++] = root->val;
		root = root->right;
	}
	free(stack);
	return ret;
}

bool isValidBST(TN* root) {
    if (!root || (!root->left && !root->right)) return true;
    int sz=0;
    int* midT=midorderTraversal(root,&sz);
    for (int i=1;i<sz;++i) {
        if (midT[i]<=midT[i-1]) return false;
    }
    return true;
}


int main() {
    TN a1,b1,c1;
    a1.val=2;a1.left=&b1; a1.right=&c1;
    b1.val=1;b1.left=NULL;b1.right=NULL;
    c1.val=3;c1.left=NULL;c1.right=NULL;

    // TN a2,b2,c2,d2,e2;
    // a2.val=5;a2.left=&b2; a2.right=&c2;
    // b2.val=1;b2.left=NULL;b2.right=NULL;
    // c2.val=4;c2.left=&d2; c2.right=&e2;
    // d2.val=3;d2.left=NULL;d2.right=NULL;
    // e2.val=6;e2.left=NULL;e2.right=NULL;

    bool isbst1=isValidBST(&a1);
    
    printf("true=%d\n",true);
    printf("isbst1=%d\n",isbst1);

}
