#include <stdio.h>
#include<string.h>

void count(int a[], int min, int max, int n)
{
	int c[max-min+1];
	memset(c, 0, (max-min+1)*sizeof(int));
	
	for(int i=0; i<n; i++)				//1 loop of order n
		c[a[i]-min]++;
	int p[max-min+2];
	p[0] = 0;
	for(int i=1; i<max-min+1; i++)		//1 loop of order max-min+1
		p[i] = p[i-1]+c[i-1];
	p[max-min+1] = p[max-min]+c[max-min];
	int i=n-1;
	int j = max-min+1;

/*	
int k;
printf("c-> ");
for(k=0; k<j; k++)
printf("%d ", c[k]);
printf("\np-> ");
for(k=0; k<=j; k++)
printf("%d ", p[k]);
printf("\n");
*/

	while(i>=0)
	{
		while(p[j]>p[j-1])
		{
			a[i] = j+min-1;
//printf("%d %d %d\n", a[i], p[j], j);
			p[j]--;
			i--;
		}
		j--;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	scanf("%d", &a[0]);
	int max = a[0], min = a[0];
	for(int i=1; i<n; i++)
	{
		scanf(" %d", &a[i]);
		if(max<a[i])
			max = a[i];
		if(min>a[i])
			min = a[i];
	}
	
	count(a, min, max, n);
	
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
