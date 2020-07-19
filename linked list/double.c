#include <stdio.h>
#include<stdlib.h>

struct list{
	int num;
	struct list *next;
	struct list *prev;
}*head, *tail;

void scan_list(int n)
{
	head = (struct list*)malloc(sizeof(struct list));
	struct list *tmp1, *tmp2;
	tmp1 = (struct list*)malloc(sizeof(struct list));
	scanf("%d", &head->num);
	head->prev = NULL;
	tmp1 = head;
	tmp2 = NULL;
	for(int i=1; i<n; i++)
	{
		tmp2 = (struct list*)malloc(sizeof(struct list));
		scanf("%d", &tmp2->num);
		tmp2->next  = NULL;
		tmp2->prev = tmp1;
		tmp1->next = tmp2;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	tail = (struct list*)malloc(sizeof(struct list));
	tail = tmp1;
	return;
}
void delete(struct list *node)
{
	(node->next)->prev = node->prev;
	(node->prev)->next = node->next;
	free(node);
}
void printlist(struct list *ptr)
{
	struct list *tmp;
	tmp = (struct list*)malloc(sizeof(struct list));
	tmp = ptr;
	printf("NULL <=> ");
	if(ptr->next!=NULL)
	{
		while(tmp!=NULL)
		{
			printf("%d <=> ", tmp->num);
			tmp = tmp->next;
		}
	}
	else
	{
		while(tmp!=NULL)
		{
			printf("%d <=> ", tmp->num);
			tmp = tmp->prev;
		}
	}
	printf("NULL\n");
	return;
}

void free_space(struct list *head)
{
	while(head->next!=NULL)
	{
		free(head->prev);
		head = head->next;
	}
	free(head);
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	scan_list(n);
	printf("entered list: ");
	printlist(head);
	printf("reverse list: ");
	printlist(tail);
	int k;
	struct list *tmp;
	tmp = (struct list*)malloc(sizeof(struct list));
a:	printf("enter the node to be deleted: ");
	scanf("%d", &k);
	tmp = head;
	int i;
	for(i=0; i<n; i++)
	{
		if(tmp->num == k)
		{
			if(i==0)
			{
				head=head->next;
				free(head->prev);
				head->prev=NULL;
			}
			else if(i==n-1)
			{
				tail = tail->prev;
				free(tail->next);
				tail->next = NULL;
			}
			else
				delete(tmp);
			break;
		}
		tmp = tmp->next;
	}
	if(i==n)
	{
		printf("Node not found. Please try again\n");
		goto a;
	}
	printf("new list    : ");
	printlist(head);
	printf("reverse list: ");
	printlist(tail);
	
	free_space(head);
	return 0;
}
