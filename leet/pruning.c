#include <stdio.h>
#include<stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*
void visit(struct TreeNode **root)
{
	printf("%d\n", (*root)->val);
	if((*root)->val==0)
		*root=NULL;
	if((*root)==NULL)
		printf("yes\n");
}
*/
/*
void visit(struct TreeNode *root)
{
	if(root->val==0)
		free(root);
}

struct TreeNode* pruneTree(struct TreeNode* root){
    if(root==NULL)
        return NULL;
    struct TreeNode *l, *r;
    l = pruneTree(root->left);
    r = pruneTree(root->right);
    if(l==NULL && r==NULL && root->val==0)
    {
    	root = NULL;
    }
    if(root==NULL)
    	printf("done\n");
    return root;
}
*/


//Done on leet.
int visit(struct TreeNode* ptr)
{
    if(ptr==NULL)
        return -1;
    int r = visit(ptr->right);
    int l = visit(ptr->left);
    if(l==-1 && ptr->left!=NULL && (ptr->left)->val!=1)
        ptr->left = NULL;
    if(r==-1 && ptr->right!=NULL && (ptr->right)->val!=1)
        ptr->right = NULL;
    if(l==-1 && r==-1 && ptr->val==0)
        return -1;
    return ptr->val;
}

struct TreeNode* pruneTree(struct TreeNode* root){
    int k = visit(root);
    return root;
}




void print(struct TreeNode *root)
{
	if(root==NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	print(root->left);
	print(root->right);
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
	root = assign(1);

	root->right=NULL;
	root->right = assign(0);

	root->right->left = assign(0);

	root->right->right = assign(1);

	root = pruneTree(root);
	print(root);
	return 0;
}
