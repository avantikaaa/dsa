#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert(struct node **ptr, int num)
{
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = num;
	tmp->next = *ptr;
	*ptr = tmp;
}

int enter(int a[], struct node *ptr, int i)
{
	while(ptr!=NULL)
	{
		a[i] = ptr->data;
		ptr = ptr->next;
		i--;
	}
	return i;
}

void free_space(struct node *ptr)
{
	if(ptr==NULL)
		return;
	free_space(ptr->next);
	free(ptr);
}
		

void radix(int a[], int n, int d)
{
	struct node *list[10], *tmp;
	for(int i=0; i<10; i++)
	{
		list[i] = (struct node *)malloc(sizeof(struct node));
		list[i] = NULL;
	}
	int b = 1;
	while(d--)
	{
		int i = n-1;
		for(int i=0; i<n; i++)
		{
			insert(&list[(a[i]/b)%10], a[i]);
		}
		for(int j=9; j>=0; j--)
		{
			tmp = list[j];
			while(tmp!=NULL)
			{
				a[i] = tmp->data;
				i--;
				tmp = tmp->next;
			}
			free_space(list[j]);
		}
	}
		

}
int dig(int n)
{
	if(n<10)
		return 1;
	return 1+dig(n/10);
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n], i;
	scanf("%d", &a[0]);
	int max = a[0];
	for(i=1; i<n; i++)
	{
		scanf(" %d", &a[i]);
		if(max<a[i])
			max = a[i];
	}
	
	int d = dig(max);
	radix(a, n, d);
	
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
