#include <stdio.h>
#include<stdlib.h>

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

struct node  
{ 
	int data; 
	int height;
	int level;
	struct node *left; 
	struct node *right;
	struct node *parent; 
}; 
  
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
	node->data = data; 
  
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

void print(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ", ptr->data);
	print(ptr->left);
	print(ptr->right);
} 

void pre(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d:  %d\t  %d\n", ptr->data, ptr->level, ptr->height);
	pre(ptr->left);
	pre(ptr->right);
}

void freespace(struct node *root)
{
	if(root==NULL)
		return;
	freespace(root->left);
	freespace(root->right);
	free(root);
}
void Height(struct node *ptr)
{
	if(ptr==NULL)
		return;
	Height(ptr->left);
	Height(ptr->right);
	if(ptr->left ==NULL)
	{
		if(ptr->right==NULL)
			ptr->height= 0;
		else
			ptr->height = ptr->right->height + 1;
	}
	else
	{
		if(ptr->right==NULL)
			ptr->height = ptr->left->height + 1;
		else
			ptr->height= min(ptr->left->height, ptr->right->height) + 1;
	}
}
void Level(struct node *ptr)
{
	if(ptr==NULL)
		return;
	if(ptr->parent==NULL)
		ptr->level=0;
	else
		ptr->level = ptr->parent->level + 1;
	Level(ptr->right);
	Level(ptr->left);
}
  
int main() 
{ 
	struct node *root = newNode(1);   
	  
	root->left        = newNode(2);
	root->left->parent = root; 
	  
	root->right       = newNode(3); 
	root->right->parent = root;

	root->left->left  = newNode(4); 
	root->left->left->parent = root->left;
  
//	getchar();
  
	Level(root);
	Height(root);
	printf("  level\theight\n");
	pre(root);
	freespace(root);
	return 0; 
}

