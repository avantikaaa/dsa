#include <stdio.h>

void merge(int a[], int i, int k, int j)
{
	int n = j-i+1;
	int b[n];
	int l=i, r=k+1, c=0;
	while(l<=k && r<=j)
	{
		if(a[l]<=a[r])
		{	
			b[c++] = a[l++];
		}
		else
		{
			b[c++] = a[r++];
		}
	}
	if(l>k)
		while(c<n)
		{
			b[c++] = a[r++];
		}
	else
		while(c<n)
			b[c++] = a[l++];
	for(c=0; c<n; c++)
		a[i+c] = b[c];
	
}

void ms(int a[], int i, int j)
{
	if(i<j)
	{
		int k = (i+j)/2;
		ms(a, i, k);
		ms(a, k+1, j);
		merge(a, i, k, j);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	scanf("%d", &a[0]);
	for(int i=1; i<n; i++)
		scanf(" %d", &a[i]);
	ms(a, 0, n-1);
	for(int i=0;i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
