/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
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

TN* invertTree(TN* root) {
	    if (!root) {
		return NULL;
	}
    // TN* tmp=root->left;
    // root->left=root->right;
    // root->right=tmp;
	// invertTree(root->left);
	// invertTree(root->right);
	TN* l=invertTree(root->left);
    TN* r=invertTree(root->right);
	root->left=r;
	root->right=l;

    return root;
}


// @lc code=end
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TN;

TN* invertTree(TN* root) {
    if (!root) {
		return NULL;
	}
    // TN* tmp=root->left;
    // root->left=root->right;
    // root->right=tmp;
	// invertTree(root->left);
	// invertTree(root->right);
    // TN* l=invertTree(root->left);
    // TN* r=invertTree(root->right);
	// root->left=r;
	// root->right=l;
    return root;
}



int* preorderTraversal(TN* root, int* sz) {
	*sz = 0;
	if (!root) return 0;
	if (!root->left && !root->right) {
		*sz = 1;
		return &(root->val);
	}
	int* ret = (int*)malloc(90 * sizeof(int));
	TN** stack = (TN**)malloc(90 * sizeof(TN*));
	int cnt = -1;
	stack[++cnt] = root;
	while (cnt != -1) {
		root = stack[cnt--];
		ret[(*sz)++] = root->val;
		if (root->right)
			stack[++cnt] = root->right;
		if (root->left)
			stack[++cnt] = root->left;
	}
	free(stack);
	return ret;
}



int main() {
    TN a,b,c,d,e,f,g;
    a.val=4;a.left=&b;a.right=&c;
    b.val=2;b.left=&d;b.right=&e;
    c.val=7;c.left=&f;c.right=&g;
    d.val=1;d.left=NULL;d.right=NULL;
    e.val=3;e.left=NULL;e.right=NULL;
    f.val=6;f.left=NULL;f.right=NULL;
    g.val=9;g.left=NULL;g.right=NULL;
    TN* inv_tn=invertTree(&a);

    int sz=0;
	int* preT = preorderTraversal(inv_tn,&sz);

	for (int i = 0; i < sz; ++i) {
		printf("%d ",preT[i]);
	}
	free(preT);
	printf("\n");
}