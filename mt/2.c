/*
void func(int a[], int *i, int n, int h, int *max)  ///Gives the actual height of the binary tree. Actually, idk.
{
	if(*i>=n)
		return;
	h++;
	if(h>*max)
		*max=h;
	(*i)++;
	if(a[*i-1]==0)
		return;
	func(a, i, n, h, max);
	(*i)++;
	func(a, i, n, h, max);
}
*/

#include<stdlib.h>
#include <stdio.h>

struct tree{
	int val;
	struct tree *left;
	struct tree *right;
};

void assign(struct tree *node, int i)
{
	node = (struct tree*)malloc(sizeof(struct tree));
	node->val = i;
}

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}
int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int height(struct tree *node)
{
	if(node==NULL)
		return 0;
	int l= height(node->left);
	int r= height(node->right);
	return min(l, r)+1;
}

void convert(struct tree *node, int a[], int n, int *i)
{
printf("aaa\n");
int k = *i;
printf("%d ", k);
	if(*i>=n)
		return;
	assign(node, a[*i]);
	(*i)++;
	if(node->val==0)
		return;
	convert(node->left, a, n, i);
	(*i)++;
	convert(node->right, a, n, i);
}

void freespace(struct tree *node)
{
	if(node==NULL)
		return;
	freespace(node->left);
	freespace(node->right);
	free(node);
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	struct tree *root;
	printf("asdfgh\n");
	int *i=0;
	convert(root, a, n, i);
	int h = height(root);
	printf("%d\n", h);
	freespace(root);
	return 0;
}
