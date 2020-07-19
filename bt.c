#include <stdlib.h>
struct btree {
int key;

struct btree* lc; 
struct btree* rc; 
struct btree* p; 
}*head;

struct list{
	int val;
	struct list *next;
};
void assign(int l)
{
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->val = l;
	ptr->next=NULL;
}
void visit(struct btree* node, int level)
{
printf("%d\n",node->key);
}

struct btree* create(long long int l,long long int r){
struct btree* x=NULL; 
long long int k = rand()%(r-l+1)+l;
x = (struct btree*) malloc (sizeof(struct btree));
x->p=NULL;
x->key =k%2341;

	if(l<k){
		x->lc=create(l,k-1);
		x->lc->p=x;
	}
	else x->lc = NULL;
	if(k<r){
		x->rc=create(k+1,r);
		x->rc->p=x;
	}
	else x->rc =NULL;

return x;

}
//Added "level" to the function
struct list* preordertraversal(struct btree* node, int level)

{
	if(node){
		struct list *ptr;
		if(level==0)
			head = ptr;
		visit(node, level);

		ptr = preordertraversal(node->lc, level+1);

		ptr = preordertraversal(node->rc, level+1);

	}
	return ptr;
}
/*
void inordertraversal(struct btree* node)

{ if(node){

inordertraversal(node->lc);
visit(node);

inordertraversal(node->rc);

}
}
void postordertraversal(struct btree* node)

{ if(node){

postordertraversal(node->lc);

postordertraversal(node->rc);
visit(node);

}
}
*/
void main (){
struct btree *root; 
long long int i,n=10000;

root = create(0,n-1);
//preordertraversal(root);
}
