#include <stdio.h>
#include<string.h>
void multiply(char m[], char n[])
{
	int l1 = strlen(m);
	int l2 = strlen(n);
	int i, j, carry=0, product, out[l1+l2-1];
	memset(out, 0, (l1+l2)*(sizeof(out[0])));
	for(i=0; i<l1; i++)
	{
		for(j=0; j<l2; j++)
		{
			product = (m[l1-1-i]-48)*(n[l2-1-j]-48) + carry;
			out[l1+l2-1-i-j] += product;
			carry = out[l1+l2-1-i-j]/10;
			out[l1+l2-j-1-i] = out[l1+l2-1-i-j]%10;
			int k=1;
			while(carry!=0)
			{
				out[l1+l2-1-i-j-k] += carry;
				carry  = out[l1+l2-1-i-j-k]/10;
				out[l1+l2-1-i-j-k] = out[l1+l2-1-i-j-k]%10;
				k++;
			}
		}
	}
	for(i=0; i<l1+l2; i++)
		printf("%d", out[i]);
	printf("\n");
}
/*
int main()
{
	char m[1000000], n[1000000];
	scanf("%s", m);
	scanf("%s", n);
	multiply(m, n);
}
*/
