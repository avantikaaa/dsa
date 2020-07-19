#include<stdio.h>
#include <stdlib.h>

struct tree{
	int data;
	int level;
	int height;
	struct node *parent;
	struct node *right;
	struct node *left;
};

void freeSpace(struct node *tmp)
{
	if(tmp==NULL)
		return;
	freeSapce(tmp->left);
	freeSpace(tmp->right);
	free(tmp);
}

int main()
{
	struct node *root;
	root = (struct node *)malloc(sizeof(struct node));
	
	root->data = 1;
	root->height = 0;
	
	struct node *tmp;
	tmp = (struct node *)malloc(6*sizeof( struct node));
	
	tmp = root->left;
	tmp->data = 2;
	tmp->parent = root;
	tmp->left->parent = tmp;
	tmp = tmp->left;
	tmp->data = 4;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp = tmp->parent;
	tmp->right->parent = tmp;
	tmp = tmp->right;
	tmp->data = 5;
	tmp->right = NULL;
	tmp->left = NULL;
	tmp = root->right;
	tmp->parent = root;
	tmp->data = 3;
	tmp->right = NULL;
	tmp->left->parent = tmp;
	tmp = tmp->left;
	tmp->data = 6;
	tmp->left = NULL;
	tmp->right->parent = tmp;
	tmp = tmp->right;
	tmp->right = NULL;
	tmp->left = NULL;
	tmp->data = 7;
	
	freeSpace(root);
	
	
	return 0;
}
