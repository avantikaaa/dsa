#include <stdio.h>
#include<string.h>

void print_arr(char a[], int i, int j)
{
	for(int k=i; k<=j; k++)
	{
		printf("%c", a[k]);
	}
}

int rank(char a[], int i, int j)
{
	int count=0;
	for(int k=i; k<=j; k++)
	{
		if(a[k] =='0')
			count--;
		else
			count++;
	}
//printf("rank %d %d %d\n", count, i, j);
	return count;
}

int check(char a[], int i, int j, int out[])
{
//printf("check %d %d\n", i, j);
	if(i>=j)
	{
		out[0] = i;
		out[1] = j;
		return rank(a, i, j);
	}
	if(a[i]=='0' && a[i+1]=='0' && a[j]=='0' && a[j-1]=='0')
	{
		int b1, b2, b3;
		b1 = rank(a, i, j);
		b2 = check(a, i+1, j, out);
		b3 = check(a, i, j-1, out);
		if(b1<b2)
		{
			if(b1<b3)
			{
				out[0] = i;
				out[1] = j;
				return b1;		//b1 is the highest.
			}
			if(b3<b2)
				//return check(a, i, j-1, out);
				return b3;
		}
		return check(a, i+1, j, out);
		
	}
	while(a[i]=='1')
	{
		i++;
	}
	while(a[j]=='1')
	{
		j--;
	}
	while(a[i]=='0' && a[i+1]=='1')
	{
		i += 2;
	}
	while(a[j]=='0' && a[j-1]=='1')
	{
		j -= 2;
	}
	return check(a, i, j, out);
}

int main()
{
	char a[100000];
	scanf("%s", a);
	int k[2];
	int out = check(a, 0, strlen(a)-1, k);
	printf("strength: %d\n", out);
	printf("sub-string: ");
	print_arr(a, k[0], k[1]);
	printf("\n");
	return 0;
}
