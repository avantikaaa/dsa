#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

bool validateStackSequences(int* pushed, int n, int* popped, int m){
//printf("bool\n");
	
	if(n<m)
		return false;
		
	int c=0, i=0, k=-1;
	int stack[n];
//	stack[0] = *pushed;
	while(c<m)
	{
	
//printf("a %d %d %d\n", k, i, c);

		while(*(pushed+i)!=*(popped+c))
		{
			k++;
			stack[k] = *(pushed+i);
//printf("b %d %d\n", stack[k], *(popped+c));
			i++;
		}
		c++;
		i++;
//printf("c %d %d\n", *(pushed+i), *(popped+c));
		while(stack[k]==*(popped+c))
		{
//printf("d %d %d\n", stack[k], *(popped+c));
			k--;
			c++;
		}
	}
//	printf("%d %d\n", m, k);
	if(c==m && k==n-m-1)
		return true;
	return false;
}

int main()
{
	int n, m, k;
	scanf("%d %d", &n, &m);
	int *push, *pop;
	push = (int *)malloc(sizeof(int)*n);
	pop = (int *)malloc(sizeof(int)*m);
	
//printf("a\n");
	scanf("%d", push);
	for(int i=1; i<n; i++)
	{
		scanf(" %d", &k);
		*(push+i) = k;
	}
	scanf("%d", pop);
	for(int i=1; i<m; i++)
		scanf(" %d", (pop+i));
	printf(validateStackSequences(push, n, pop, m)?"True\n":"False\n");
	return 0;
}
