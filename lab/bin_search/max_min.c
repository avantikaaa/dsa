#include <stdio.h>
#include<stdbool.h>

bool check_sum(int k, int arr[], int sum, int n)		//Checks whether a minimum subarray "sum" is possible to be obtained by k subarrays.
{
	int i, count=0, s = 0;
	for(i=0; i<n; i++)
	{
		s += arr[i];
		if(s>=sum)
		{
			count++;
			s=0;
		}
		if(count>=k)
			return true;
	}
	return false;
}

int check(int arr[], int k, int min, int max, int n)
{
	if(min>max)
		return max;
	int mid = (min+max)/2;
	if(check_sum(k, arr, mid, n)==true)
		return check(arr, k, mid+1, max, n);
	return check(arr, k, min, mid-1, n);				//if it is false
}

int main()
{
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	int i, arr[n];
	scanf("%d", &arr[0])
	int sum=arr[0];
	for(i=1; i<n; i++)
	{
		scanf(" %d", &arr[i]);
		sum+=a[i];
	}
	int out = check(arr, k, 0, sum, n);
	
	printf("%d\n", out);
	
	return 0;
}
