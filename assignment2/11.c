#include <stdio.h>
#include<stdlib.h>

struct bst{
	int val;
	int nodes;
	struct bst *left;
	struct bst *right;
	struct bst *parent;
};

struct bst *assign(int key)
{
	struct bst *node = (struct bst*)malloc(sizeof(struct bst));
	
	node->val = key;
	
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	
	return node;
}
void incrementNodes(struct bst *node)
{
	if(!node)
		return;
	
	node->nodes++;
	return incrementNodes(node->parent);
}

void insert(struct bst **node, struct bst *p, int key)
{
	if(!(*node))
	{
		*node = assign(key);
		(*node)->parent = p;
		
		(*node)->nodes = 1;
		incrementNodes(p);
	}
	if((*node)->val == key)
		return;
	
	if((*node)->val > key)
		return insert(&((*node)->left), *node, key);
	
	return insert(&((*node)->right), *node, key);
}

int findRank(struct bst *node, int key, int rank)
{
	if(!node)
		return -1;
	int otherNode = 1;
	if(node->val == key)
	{
		if(node->left)
			otherNode += (node->left)->nodes;
		return rank + otherNode;
	}
	if(node->val > key)		//go left
	{
		return findRank(node->left, key, rank);
	}
	//go right
	if(node->left)
		otherNode += (node->left)->nodes;
	return findRank(node->right, key, rank+otherNode);
	
}

/*
void printBST(struct bst *node)
{
	if(!node)
		return;
	printBST(node->left);
	printf("%d %d\n", node->val, node->nodes);
	printBST(node->right);
}
*/

int main()
{
	int queries, i;
	printf("Number of queries: ");
	scanf("%d", &queries);
	
	struct bst *head = NULL;
	
	int q, key;
	for(i=0; i<queries; i++)
	{
		scanf("%d %d", &q, &key);
		if(q==1)
		{
			insert(&head, NULL, key);
		}
		else if(q == 2)
		{
		printf("hello- ");
			int out = findRank(head, key, 0);
			if(out==-1)
				printf("no\n");
			else
				printf("%d\n", out);
		}
//		printBST(head);
//		printf("\n");
	}
	
	return 0;
}
