#include <stdio.h>
#include <stdlib.h>

struct bst{
	int key;
	int freq;
	int smaller;
	struct bst *left, *right;
};

void assign(struct bst **node, int val){
	(*node) = (struct bst*)malloc(sizeof(struct bst));
	(*node)->key = val;
	(*node)->freq = 1;
	(*node)->smaller = 0;
	(*node)->left = NULL;
	(*node)->right = NULL;
}

int add(struct bst **node, int val, int count){
	//printf("hello %d ", val);
	if (!(*node)){
		assign(node, val);
		return count;
	}
	
	if ((*node)->key > val){
		(*node)->smaller += 1;
	//	printf("debug %d %d %d\n", val, count, (*node)->key);
		return add(&((*node)->left), val, count);
	}

	else if ((*node)->key < val){
		//count += (*node)->freq;
		return add(&((*node)->right), val, count + (*node)->freq + (*node)->smaller);
	}
	//key == val
	(*node)->freq += 1;
	return count + (*node)->smaller;
}

struct bst* getCount(int nums[], int count[], int n){
	struct bst *head;
	
	assign(&head, nums[n-1]);
	count[n-1] = 0;
	for (int i = n-2; i >= 0; i--)
		count[i] = add(&head, nums[i], 0);
	
	return head;
}

void print(struct bst *node){
	if(!node)
		return;
	print(node->left);
	printf("%d %d %d\n", node->key, node->freq, node->smaller);
	print(node->right);
}

void freeall(struct bst *node){
	if (!node)
		return;
	freeall(node->left);
	freeall(node->right);
	free(node);
}

int main(){
	//struct bst *head;
	int nums[9] = {10, 5, 23, 10, 5, 8, 6, 9, 3};
	int count[9];
	//assign(&head, nums[0]);
	
	struct bst *head = getCount(nums, count, 9);
	
	for (int i=0; i<9; i++)
		printf("%d ", count[i]);
	printf("\n");
	
//	print(head);
	freeall(head);
	
	return 0;
}
