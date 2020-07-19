#include<stdio.h>
#include<stdbool.h>

bool search(int ar[], int n, int num, int l)
{
	if (n==0)
		return false;
	int sum=0, i, j;
	for(j=0; j<n; j++)
		sum += ar[j];
	if(sum==num)
		return true;
	for(i=0; i<l-n+1; i++)
	{
		sum += ar[i+n]-ar[i];
		if(sum==num)
			return true;
	}
	return search(ar, n-1, num, l);
}

int main()
{
	int n, k;
	scanf("%d", &n);
	int ar[n];
	for(int i=0; i<n; i++)
		scanf("%d", &ar[i]);
	printf("Enter number: ");
	scanf("%d", &k);
	printf("%d\n", search(ar, n, k, n));
printf(search(ar, n, k, n) ? "true\n" : "false\n");
	return 0;
}
