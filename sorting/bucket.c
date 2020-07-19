#include <stdio.h>
#include<stdlib.h>

struct buc{
	int num;
	struct buc *next;
};

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void divide(int a[], int n, struct buc *list[])
{
	struct buc *tmp;
	for(int i=0; i<n; i++)
	{
		tmp = (struct buc*)malloc(sizeof(struct buc));
		tmp = list[a[i]%10];
		while(tmp!=NULL)
			tmp = tmp->next;
		tmp->next = NULL;
		tmp->num = a[i];
	}
}

void sort(struct buc *ptr)
{
	if(ptr==NULL)
		return;
	int count = 1;
	struct buc *tmp = ptr;
	while(tmp->next!=NULL)
	{
		count++;
		if(tmp->num>(tmp->next)->num)
			swap(&tmp->num, &((tmp->next)->num));
		tmp = tmp->next;
	}
	for(int i=1; i<count; i++)
	{
		while(tmp->next!=NULL)
		{
			if(tmp->num>(tmp->next)->num)
				swap(&tmp->num, &((tmp->next)->num));
			tmp = tmp->next;
		}
	}
}

void bucket(int a[], int n)
{
	struct buc *list[10], *tmp;
	int i, j=0;
	for(i=0; i<n; i++)
	{
		list[i] = (struct buc *)malloc(sizeof(struct buc));
		list[i] = NULL;
	}
	divide(a, n, list);
	
	for(i=0; i<10; i++)
	{
		sort(list[i]);
		tmp = list[i];
		while(tmp!=NULL)
		{
			a[j++] = tmp->num;
			tmp = tmp->next;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n], i;
	scanf("%d", &a[0]);
	for(i=1; i<n; i++)
		scanf(" %d", &a[i]);
	bucket(a, n);
}
