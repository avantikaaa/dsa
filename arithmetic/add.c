#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int add(char n[], char m[], char out[])
{
	int l1 = strlen(n);
	int l2 = strlen(m);
	int sum, carry=0;
	if (l1>l2)
	{
		for(int i=0; i<l2; i++)
		{
			sum = n[l1-1-i]+m[l2-1-i]-96+carry;
			carry = sum/10;
			out[i] = sum%10+48;
		}
		for(int i=l2; i<l1; i++)
		{
			sum = n[l1-1-i]+carry-48;
			carry = sum/10;
			out[i] = sum%10+48;
		}
		return carry;
	}
	else
	{
		for(int i=0; i<l1; i++)
		{
			sum = n[l1-1-i]+m[l2-1-i]-96+carry;
			carry = sum/10;
//			out[i] = sum%10+48;
		}
		for(int i=l1; i<l2; i++)
		{
			sum = m[l2-1-i]+carry-48;
			carry = sum/10;
			out[i] = sum%10+48;
		}
		return carry;
	}
}

/*
int main()
{
	char n[1000000], m[1000000];
	scanf("%s", n);
	scanf("%s", m);
	add(n, m);
	return 0;
}
*/
