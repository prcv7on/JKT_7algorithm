/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    int ld=maxDepth(root->left)+1;
    int rd=maxDepth(root->right)+1;
    return ld>rd ? ld : rd;
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

struct TreeNodeStruct {
    int depth;
    TN* node;
};
typedef struct TreeNodeStruct STN;

int maxDepth(TN* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    STN* stack = (STN*)malloc(200 * sizeof(STN));
    int maxd=0;
    int d=0;
    int cnt=-1;
    while (root || cnt!=-1) {
        while (root) {
            stack[++cnt].node=root;
            stack[cnt].depth=d+1;
            ++d;
            root=root->left;
        }
        root = stack[cnt].node;
        d=stack[cnt].depth;
        if (maxd<d) maxd=d;
        --cnt;
        root=root->right;
    }
    return maxd;

}



int main() {
    TN a,b,c,d,e,f;
    a.val=3; a.left=&b;  a.right=&c;
    b.val=9; b.left=NULL;b.right=NULL;
    c.val=20;c.left=&d;  c.right=&e;
    d.val=15;d.left=&f;d.right=NULL;
    e.val=7; e.left=NULL;e.right=NULL;
    f.val=6; f.left=NULL;f.right=NULL;

    int deep=maxDepth(&a);
    printf("%d\n",deep);

}
