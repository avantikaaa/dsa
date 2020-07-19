#include <stdio.h>
#include<string.h>
#include<stdlib.h>

/*
struct hash{
	int ind;
	struct hash *next;
};

void free_space(struct hash *tmp)
{
	if(tmp==NULL)
		return;
	free_space(tmp->next);
	free(tmp);
}

int bin_int(int l, char a[], int index)		//works only for binary conversion.
{
	int product = 0;
	for(int i=index; i<index+l; i++)
	{
		product *= 2;
		int k=a[i]-48;
		product += k;
	}
	return product;
}

int search(char str1[], char str2[], int l)
{
printf("func %d\n", l);
	if(l==0)
		return 0;
		
	int power = 1, num1=0, num2=0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0; i<l; i++)
	{
		power *= 2;
		num1 *= 2;
		num1 += str1[i]-48;
		num2 *= 2;
		num2 += str2[i]-48;
	}
printf("func\n");

	struct hash *list[31];

printf("a\n");
printf("%d %d\n", num1, num2);
printf("b %d\n", num1%31);

	struct hash *tmp;
printf("1\n");

	for(int i=0; i<31; i++)
	{
		list[i] = (struct hash*)malloc(10*sizeof(struct hash));
		list[i] = NULL;
	}
	
printf("2\n");
	tmp = (struct hash*)malloc(sizeof(struct hash));
	tmp->ind = 0;
	list[num1%31]=tmp;
	tmp->next = NULL;
printf("%d %d\n", tmp->ind, list[num1%31]->ind);

	list[num1%31]->ind = 0;
	list[num1%31]->next = NULL;

printf("3\n");

//	tmp->next = NULL;

//	tmp->ind = 0;								//Assigning the first hash index

printf("c\n");

	for(int i=1; i<len1-l; i++)								//Creating a hash table
	{

printf("d %d", i);

		num1 -= (str1[i-1]-48)*power;
		num1 *= 2;
		num1 += str1[i+l-1]-48;
	
		tmp = (struct hash*)malloc(sizeof(struct hash));
		tmp = list[num1%31];
		while(tmp!=NULL)
			tmp = tmp->next;
		tmp->ind = i;
		tmp->next = NULL;

printf("e\n");

	}
printf("f\n");
	int check1(int num2)
	{
		if(list[num2%31]!=NULL)
			return 1;
		return 0;
	}
	int check2(int index2, int num2)
	{
		struct hash *tmp;
		tmp = list[num2%31];
		while(tmp!=NULL)
		{
			for(int i=0; i<l; i++)
			{
				if(str1[i+tmp->ind]!=str2[index2+i])
					return 0;
				return 1;
			}
		}
	}	
	
	if(check1(num2)==1)
		if(check2(0, num2)==1)
			return l;
		
	for(int i=1; i<len2-l; i++)
	{
		num2 -= power*(str2[i-1]-48);
		num2 *= 2;
		num2 += str2[i+l-1]-48;
		if(check1(num2)==1)
			{
				if(check2(i, num2)==1)
					return l;
			}
	}
	for(int i=0; i<31; i++)
	{
		free_space(list[i]);
	}
	return search(str1, str2, l-1);
}
	

int main()
{

	char str1[100000], str2[100000];
	scanf("%s", str1);
	scanf("%s", str2);
	int out;

printf("main a\n");

	if(strlen(str1)>strlen(str2))
		out = search(str1, str2, strlen(str2));
	else
		out = search(str1, str2, strlen(str1));

printf("successful\n");

	printf("%d\n", out);
	return 0;
}
*/

void search(

		
/*
		
THIS IS AN INCOMPLETE CODE. I HAVE LOST THE PATIENCE TO DO THIS. I STILL DON'T KNOW HOW TO USE A HASH TABLE. MAYBE I KNOW HOW TO USE, BUT I DON'T HAVE THE PATIENCE TO CREATE THE HASH TABLE CURRENTLY.

*/
