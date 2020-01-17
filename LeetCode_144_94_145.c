

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TN;


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

int* inorderTraversal(TN* root, int* sz) {
	*sz = 0;
	if (!root) return 0;
	if (!root->left && !root->right) {
		*sz = 1;
		return &(root->val);
	}
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

int* postorderTraversal(TN* root, int* sz) {
	*sz = 0;
	if (!root) return 0;
	if (!root->left && !root->right) {
		*sz = 1;
		return &(root->val);
	}
	int* ret = (int*)malloc(90 * sizeof(int));
	TN** stack = (TN**)malloc(90 * sizeof(TN*));
	TN* pre = NULL;
	int cnt = -1;
	while (root || cnt != -1) {
		while (root) {
			stack[++cnt] = root;
			root = root->left;
		}
		root = stack[cnt];
		if (root->right && root->right != pre) { //栈顶右子树存在且没被访问
			root = root->right;
		}
		else {									 //栈顶右子树不存在或已被访问过
			--cnt;
			ret[(*sz)++] = root->val;
			pre = root;
			root = NULL;		//防止栈顶左子树重复进栈
		}
	}
	return ret;
}



int main()
{
	TN a, b, c, d, e, f;
	a.val = 3; a.left = &b; a.right = &c;
	b.val = 4; b.left = &d; b.right = &e;
	c.val = 5; c.left = &f; c.right = NULL;
	d.val = 6; d.left = NULL; d.right = NULL;
	e.val = 7; e.left = NULL; e.right = NULL;
	f.val = 8; f.left = NULL; f.right = NULL;
	//TN a, b, c;
	//a.val = 1; a.left = NULL; a.right = &b;
	//b.val = 2; b.left = &c;   b.right = NULL;
	//c.val = 3; c.left = NULL; c.right = NULL;
	int sz=0;
	int* preT = postorderTraversal(&a,&sz);

	for (int i = 0; i < sz; ++i) {
		printf("%d ",preT[i]);
	}
	free(preT);
	printf("\n");

	system("pause");

}





