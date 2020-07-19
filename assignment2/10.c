#include    <stdio.h>
#include   <stdlib.h>
#include<stdbool.h>

struct bst{
	int val;
	struct bst *left;
	struct bst *right;
	struct bst *parent;
};

struct seq{
	int val;
	int nodes;
	struct bst *left;
	struct bst *right;
};

struct bst *assign(int a)
{
	struct bst *node = (struct bst *)malloc(sizeof(struct bst));
	node->val = a;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	
	return node;
}

void buildLeft(int a[], struct bst **node, struct bst *p, int s, int e, int n)
{
	if(s > e || s< 0 || e >= n)
		return;
	
	int mid = (s + e)/2;
	(*node) = assign(a[mid]);
	
	(*node)->parent = p;
	
	buildLeft(a, &((*node)->left), *node, s, mid-1, n);
	buildLeft(a, &((*node)->right), *node, mid+1, e, n);
	
}

void buildRight(int a[], struct bst **node, struct bst *p, int s, int e, int n)
{
	if(s > e || s < 0 || e >= n)
		return;
	
	int mid = (s+e)/2;
	(*node)  = assign(a[mid]);
	
	(*node)->parent = p;
	
	buildRight(a, &((*node)->left), *node, mid+1, e, n);
	buildRight(a, &((*node)->right), *node, s, mid-1, n);
	
}

struct seq *buildSeq(int a[], int k, int n)
{
	struct seq *head = (struct seq*)malloc(sizeof(struct seq));

	head->val = a[k];
	head->nodes = n;
	
	buildLeft(a, &(head->left), NULL, 0, k-1, n);
	buildRight(a, &(head->right), NULL, k+1, n-1, n);
	
	return head;
}

/*
bool search(struct bst *node, int key)
{
	if(!node)
		return false;
	
	if(node->val == key)
		return true;
	if(node->val < key)
		return search(node->right, key);
	return search(node->left, key);
}
*/

int insert(struct bst **node, struct bst *p, int key)
{
	if((*node)==NULL)
	{
		(*node) = assign(key);
		(*node)->parent = p;
		return 1;
	}
	
	if((*node)->val == key)
		return 0;
	
	if((*node)->val > key)
		return insert(&((*node)->left), *node, key);
	return insert(&((*node)->right), *node, key);
}

int insertKey(struct seq *head, int key)
{
	if(key == head->val)			//If key== max value of the array
		return head->nodes;
	
	bool flag = insert(&(head->left), NULL, key);
	if(!flag)
	{
		flag = insert(&(head->right), NULL, key);
	}
	head->nodes += flag;
	return head->nodes;
}

void printLeft(struct bst *ptr)
{
	if(!ptr)
		return;
		
	printLeft(ptr->left);
	printf("%d ", ptr->val);
	printLeft(ptr->right);
}

void printRight(struct bst *ptr)
{
	if(!ptr)
		return;
		
	printRight(ptr->right);
	printf("%d ", ptr->val);
	printRight(ptr->left);
	
	return;
}

void printSeq(struct seq *ptr)
{
	printLeft(ptr->left);
	printf("%d ", ptr->val);
	printRight(ptr->right);
	printf("\n");
	return;
}

int main()
{
	int n;
//	printf("Number of elements: ");
	scanf("%d", &n);
	int a[n], i, k=1;
//	printf("Array of elements: ");
	scanf("%d", &a[0]);
	for(i=1; i<n; i++)
	{
		scanf(" %d", &a[i]);
		if(a[i] > a[i-1])
			k = i;
	}
	
	 struct seq *head = buildSeq(a, k-1, n);
	 
	 int queries, key;
//	 printf("Number of queries: ");
	 scanf("%d", &queries);
	 for(i=0; i<queries; i++)
	 {
	 	printf("Value to be inserted: ");
	 	scanf("%d", &key);
//	 	printf("Number of elements in new sequence: ");
	 	printf("%d\n", insertKey(head, key));
	 }
	 
	 printSeq(head);
	
	return 0;
}
