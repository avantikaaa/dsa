#include <stdio.h>

int max_sum(int arr[], int n)
{
	int sum=0, max=0;
	for(int i=0; i<n; i++)
	{
		sum+= arr[i];
		if(sum>max)
			max = sum;
		if(sum<0)
			sum = 0;
	}
	return max;
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	scanf("%d", &arr[0]);
	for(int i=1; i<n; i++)
		scanf(" %d", &arr[i]);
	int out = max_sum(arr, n);
	printf("%d\n", out);
	return 0;
}
