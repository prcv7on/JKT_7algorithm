/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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
int minDepth(TN* root){
    if (!root) return 0;
    int ld=minDepth(root->left);
    int rd=minDepth(root->right);
    return (root->left && root->right) ? 1+fmin(ld,rd) : 1+ld+rd;
}


// @lc code=end



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TN;

struct TreeNodeStruct {
    int depth;
    TN* node;
};
typedef struct TreeNodeStruct STN;

// int minDepth(struct TreeNode* root){
//     if (!root) return 0;
//     int ld=minDepth(root->left);
//     int rd=minDepth(root->right);
//     return (root->left && root->right) ? 1+fmin(ld,rd) : 1+ld+rd;
// }

//循环数组实现队列
// int minDepth(struct TreeNode* root){
//     if (!root) return 0;
//     if (!root->left && !root->right) return 1;
//     STN* que = (STN*)malloc(200 * sizeof(STN));
//     int mind=0;
//     int d=1;
//     int cnt=-1;


// }


int main() {
    TN a,b,c,d,e,f;
    a.val=3; a.left=&b;  a.right=&c;
    b.val=9; b.left=NULL;b.right=NULL;
    c.val=20;c.left=&d;  c.right=&e;
    d.val=15;d.left=&f;d.right=NULL;
    e.val=7; e.left=NULL;e.right=NULL;
    f.val=6; f.left=NULL;f.right=NULL;

    int deep=minDepth(&a);
    printf("%d\n",deep);


    // double a=1,b=2;
    // double mina=fmin(a,b);
    // printf("%f\n",mina);

}