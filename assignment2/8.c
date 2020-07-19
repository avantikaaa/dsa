#include <stdio.h>
#include<stdlib.h>

struct bst{
	int val;
	struct bst *left;
	struct bst *right;
	struct bst *parent;
};

struct avl{
	struct bst *node;
	int nodes;
	int height;
};



struct avl *maxSubTree()
{

}

struct bst *assign(int key)
{
	struct bst *node = (struct bst*)malloc(sizeof(struct bst));
	node->val = key;

	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	
	return node;
}

void buildBST(int a[], struct bst *node, struct bst *p, int s, int e, int n)
{
	if(s < 0 || s > e || e >= n)
		return;
	
	int mid = (s + e)/2;
	node = assign(a[mid]);
	
	node->parent = p;
	buildBST(a, node->left, node, s, mid-1, n);
	buildBST(a, node->right, node, mid+1, s, n);
}

void printSubTree(struct bst *ptr)
{
	if(!ptr)
		return;
	printSubTree(ptr->left);
	printf("%d ", ptr->val);
	printSubTree(ptr->right);
}

int main()
{
	int n;
	printf("Number of elements: ");
	scanf("%d", &n);
	
	int a[n], i;
	printf("Array: ");
	scanf("%d", &a[0]);
	for(i=1; i<n; i++)
		scanf(" %d", &a[i]);

	struct bst *head;
	buildBST(a, head, NULL, 0, n-1, n);
	
	printSubTree(/*functionCall(head)*/);
	printf("\n");
	
	return 0;
}
