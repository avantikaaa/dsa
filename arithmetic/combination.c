#include<stdio.h>
#include<stdlib.h>
#include"multiply.h"
//#include"factorial.h"
#include"add.h"

int main()
{
	char n[1000000], m[1000000];
	int k, loop=1, tmp;

	printf("Enter first number: ");
	scanf("%s", n);
	printf("Enter second number: ");
	scanf("%s", m);

	printf("\n1 for add\n2 for multiply\nEnter number: ");
	scanf("%d", &k);
	if(k==1)
	{
		int l;
		if(l1>l2)
			l = l1+1;
		else
			l = l2+1;
		int out[l]
		printf("\nThe sum of the given numbers: ");
		int carry = add(m, n, out);
		printf("%d", carry);
		for(int i=l; i>=0; i--)
			printf("%d", out[i]);
	}
	else if (k==2)
	{
		printf("\nProduct of the given numbers: ");
		multiply(m, n);
	}
	else
	{
		printf("\n*********************** Invalid  Operation ***********************\n*************************** Bye Bye ***************************\n");
	}

	return 0;
