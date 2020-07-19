#include <stdio.h>
#include<stdbool.h>

typedef struct list{
	int data;
	struct list *next;
};

bool ProAss1(int x[], list *head, int n)
{
