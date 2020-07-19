#include <stdio.h>


int height(int a[], int  n)
{
	int c=0;
	int max=0, i=0;
	while(i<n)
	{
		while(a[i]==1)
		{
			c++;
			i++;
		}
		if(c>max)
			max = c;
		int k=0;
		while(a[i]==0)
		{
			k++;
			i++;
		}
		c = c-k+1;
	}
	return max;	
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	int h = height(a, n);
	printf("%d\n", h);

	return 0;
}
