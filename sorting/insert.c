#include <stdio.h>

void insert(int arr[], int n)
{
	int i, j, key;
	for(i=1; i<n; i++)
	{
		j = i-1;
		key = arr[i];			//current element
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	scanf("%d", &arr[0]);
	for(int i=1; i<n; i++)
		scanf(" %d", &arr[i]);
	insert(arr, n);
	printf("After sorting -> %d", arr[0]);
	for(int i=1; i<n; i++)
		printf(", %d", arr[i]);
	printf("\n");
	return 0;
}
