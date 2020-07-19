/*
Given :- Array of size 'n',  'k' number of sub arrays.
RTF :-    Maximum of the minimum of the sum of elements when the array is divided into 'k' sub-arrays.
*/
#include <stdio.h>
#include<stdbool.h>
/*
To check whether it is possible to get a minimum sum of 'm' of 'k' sub arrays of a given array of size 'n'
*/
bool sum_possible( int a[], int k, int n, int m)
{
	int sum = 0, count = 0;
	for(int i=0; i<n; i++)
	{
		sum+=a[i];
		if(sum>=m)
		{
			count++;
			sum=0;
		}
		if(count>=k)
			return true;
	}
	return false;
}
/*
1. Check mid element.
2. If true, left = mid+1
3. Else, right = mid-1
4. when left>right, pass right or left-1.
*/
int max_sum(int left, int right, int a[], int k, int n)
{
	if(left>right)
		return right;
	int mid = (left+right)/2;
	if( sum_possible(a, k, n, mid)==true)
		return max_sum(mid+1, right, a, k, n);
	return max_sum(left, mid-1, a, k, n);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);			//Number of elements in the array and number of sub arrays.
	int a[n];
	scanf("%d", &a[0]);
	int min=a[0], sum=a[0];			// Keeping the track of least number and the sum of all elements.
	for(int i=1; i<n; i++)			//INPUT
	{
		scanf(" %d", &a[i]);
		if(min>a[i])
			min = a[i];
		sum+=a[i];
	}
	int m = max_sum(min, sum, a, k, n);
	printf("%d\n", m);				//OUTPUT
	return 0;
}
