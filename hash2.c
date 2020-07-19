#include   <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include<stdbool.h>
/*
This program gives the correct output for only a few numbers 
*/
struct node{
	int num;
	struct node *next;
};

void free_space(struct node *ptr)
{
	if(ptr==NULL)
		return;
	free_space(ptr->next);
	free(ptr);
}

void clear_hash(struct node *hash[], int n)
{
	for(int i=0; i<n; i++)
	{
		free_space(hash[i]);
	}
	return;
}
void insert(struct node **head, int n)
{
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->next = *head;
	tmp->num = n;
	*head = tmp;
}

bool check(char str1[], char str2[], int i1, int i2, int l)				//Brute-force checking.
{
	int i;
	for(i=0; i<l; i++)
	{
		int a = str1[i1+i];
		int b = str2[i2+i];
		if(a!=b)
		{
printf("%d %d\n", i2, l);
			return false;
		}
	}
	return true;
}

int create_hash(char str1[], char str2[], int l)
{
/*
char c = '0';
printf("%d ", c);
printf("len = %d\n", l);
*/

	if(l==0)
	{
		printf("no match found\n");
		return 0;
	}
	
	int prime = 127;						//You can change the value of prime anytime.
	struct node *hash[prime];
	int i, num1=0, num2=0, power=1;
	for(i=0; i<l; i++)
	{
		num1 *= 2;
		num1 += str1[i]-48;
		
		num2 *= 2;
		num2 += str2[i]-48;
		
		power *= 2;
	}
	power /= 2;
//printf("power %d\n", power);

	for(i=0; i<prime; i++)
	{
		hash[i] = (struct node *)malloc(sizeof(struct node));
		hash[i] = NULL;
	}
	int rem;
	rem = num1%prime;
	insert(&hash[rem], 0);			//Creating the hash table.
	for(i=1; i<strlen(str1)-l+1; i++)
	{
		num1 -= (str1[i-1]-48)*power;
		num1 *= 2;
		num1 += str1[i+l-1]-48;
		
		rem = num1%prime;
		insert(&hash[rem], i);
	}

/*
	i--;
	printf("string1 ");
	for(int j=0; j<l; j++)
		printf("%c", str1[i+j]);
	printf("\n");
*/
	
	
	rem = num2%prime;			//rem is now wrt string-2
	struct node *tmp;
	tmp = hash[rem];

//printf("num1 %d %d\n", num1, num2);

	while(tmp!=NULL)
	{

//printf("tmp %d\n", tmp->num);

		if(check(str1, str2, tmp->num, 0, l)==true)
		{
//printf("bbb %d\n", tmp->num);
/*
			printf("indices:\n\tstr1: %d\n\tstr2: 0\n", tmp->num);
			for(int j = 0; j<l; j++)
				printf("%c", str2[j]);
			printf("\n");
*/

			return l;
		}
		tmp = tmp->next;
	}
	for(i=1; i<strlen(str2)-l+1; i++)
	{
		//change num2
		num2 -= (str2[i-1]-48)*power;
		num2 *= 2;
		num2 += str2[i+l-1]-48;
		
		rem = num2%prime;
		tmp = hash[rem];
		while(tmp!=NULL)
		{
			if(check(str1, str2, tmp->num, i, l)==true)
			{
//printf("aaa\n");
/*
				printf("indices:\n\tstr1: %d\n\tstr2: %d\n", tmp->num, i);
				for(int j = 0; j<l; j++)
					printf("%c", str2[j+i]);
				printf("\n");
*/

				return l;
			}
			tmp = tmp->next;
		}
	}
/*
	i--;
	printf("string2 ");
	for(int j=0; j<l; j++)
		printf("%c", str2[i+j]);
	printf("\n");
*/

	clear_hash(hash, prime);
	return create_hash(str1, str2, l-1);
}


int main()
{
	char str1[10000], str2[10000];
	scanf("%s", str1);
	scanf("%s", str2);
	int l=0;
	if(strlen(str1)>strlen(str2))
	{
		l = create_hash(str1, str2, strlen(str2));
	}
	else
		l = create_hash(str2, str1, strlen(str1));
		
	printf("Length of max common sub-string = %d\n", l);
	return 0;
}
