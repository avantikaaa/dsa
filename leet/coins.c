#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

 
int coin(struct TreeNode* ptr, int *moves)
{
	if(ptr==NULL)
		return 0;
	int l = coin(ptr->left, moves);
	int r = coin(ptr->right, moves);
	*moves += fabs(l)+ fabs(r);
	return ptr->val-1+l+r;
}

int distributeCoins(struct TreeNode* root){
	int moves=0;
	int k = coin(root, &moves);
	return moves;
}

struct TreeNode* assign(int i)
{
	struct TreeNode *tmp;
	tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	tmp->val = i;
//	tmp->right = NULL;
//	tmp->left = NULL;
	return(tmp);
}

int main()
{
	struct TreeNode *root;
	root = assign(3);
	root->left=assign(0);
	root->right = assign(0);
	printf("%d\n", distributeCoins(root));
	root->val=0;
	root->left->val=3; 
	root->right->val=0;
	printf("%d\n", distributeCoins(root));
	return 0;
}
