/*

This program takes base as an input. For ease, you can change it to 16. But you will have to make modifications as with letters, there can be some problem

*/


#include <stdio.h>
#include<stdbool.h>
#include<string.h>

int char_bin(int l, char str[], int index, int base)	//changes binary number of length l to integer
{
	int s=0;
	for(int i=0; i<l; i++)
	{
		s = base*s +(str[index+i]-48);
	}
	return s;
}
int power(int k, int n)				//calculates the value of k^n(k to the power n)
{
	int product=1;
	for(int i=0; i<n; i++)
		product *= k;
	return product;
}

int substring(int l, char str1[], char str2[], int base)	//l = length of substring
{
	if(l==0)
		return 0;

	int p = power(base, l);
	int num1 = char_bin(l, str1, 0, base);
	int num2 = char_bin(l, str2, 0, base);
	if (num1==num2)
		return l;
//printf("1\n");
	for(int i=1; i<strlen(str1)-l; i++)
	{
		int p1 = str1[i-1]-48;
		num1 -= p*p1;
		num1 *= base;
		num1 += (str1[i+l-1]-48);
		for(int j=1; j<strlen(str2)-l; j++)
		{
//printf("a %d %d %d\n", num1, num2, l);
			int p2 = (str2[j-1]-48);
			num2 -= p*p2;
			num2 *= base;
			num2 += (str2[j+l-1]-48);
//printf("b %d %d %d\n", num1, num2, l);
			if(num1==num2)
{
//printf("2 %d %d %d %d\n", i, j, num1, num2);
				return l;
}
		}
	}
//printf("3\n");
	return substring(l-1, str1, str2, base);
}

int main()
{
	char str1[100], str2[100];
	scanf("%s", str1);
	scanf("%s", str2);
	int l, base;
	printf("Enter base of the numbers: ");
	scanf("%d", &base);
	if(strlen(str1)<strlen(str2))
		l=strlen(str1);
	else
		l= strlen(str2);
	printf("Length of the longest common sub-string: %d\n", substring(l, str1, str2, base));
	return 0;
}
