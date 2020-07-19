#include<stdio.h>
#include<stdbool.h>

bool check_sum(int arr[], int sum, int k, int n)
{
//printf("sum- %d k- %d n- %d ", sum, k, n);
	int i, s=0, count=1;
	for(i=0; i<n; i++)
	{
		if(arr[i]>sum)
			return false;
		s+=arr[i];
		if(s>=sum)
		{
//printf("s- %d count- %d i- %d\n", s, count, i);
			s=arr[i];
			count++;
		}
	}
	if(count<=k)
		return true;
	return false;
}

int check(int arr[], int k, int min, int max, int n)
{
	if(min>max)
		return min;
	int mid = (min+max)/2;
	if(check_sum(arr, mid, k, n)==false)
	{
		return check(arr, k, mid+1, max, n);
	}
	return check(arr, k, min, mid-1, n);
}

int main()
{
	int i, n, k, time;
	scanf("%d %d %d", &n, &k, &time);
	int arr[n], sum;
	scanf("%d", &arr[0]);
	sum=arr[0];
	for(i=1; i<n; i++)
	{
		scanf(" %d", &arr[i]);
		sum+= arr[i];
	}
	int out = check(arr, k, 0, sum, n);
//	if( check(
	printf("Minimum time for participants to finish eating = %d\n", out*time);
	
	return 0;
}
