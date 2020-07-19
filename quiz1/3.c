#include <stdio.h>
int count = 0;

int bs(int a[], int l. int r, int n)
{
	if(l>=r)
		return r;
	int mid = (l+r)/2;
	if(a[mid]==n)
		return mid;
	if(a[mid]<num)
		return bs(a, mid+1, n);
	return bs(a, l, mid-1, n);
}


int merge(int arr[], int left, int mid, int right)
{
	int b[right-left+1];
	int i = left, j = mid+1, k=0;
	while(i<=mid && j <=right)
	{
		if(arr[i]<=arr[j])
		{
			b[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			b[k] = arr[j];
			count += bs(arr, 0, k,
			k++;
			j++;
		}
	}
	if(i>mid)
	{
		while(j<=right)
		{
			count += mid-i+1;
			b[k++] = arr[j++];
		}
	}
	else
		while(i<=mid)
			b[k++] = arr[i++];
	return count;
}

void mergeSort(int arr[], int left, int right)
{
	if(left>=right)
		return;
	int mid = (left+right)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	count = merge(arr, left, mid, right);
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	scanf("%d", &arr[0]);
	for (int i=1; i<n; i++)
		scanf(" %d", &arr[i]);
	mergeSort(arr, 0, n-1);
	printf("%d\n", count);
}
