#include <stdio.h>
#include<stdlib.h>

int partition(int a[], int i, int j, int pivot)
{
	int l = i, r=j;
	while(l<=r)
	{
		while(a[l]<=pivot && l<=r)
			l++;
		while(a[r]>pivot && l<=r)
			r--;
		//swap
		if(l<=r)
		{
			int tmp = a[r];
			a[r] = a[l];
			a[l] = tmp;
			l++;
			r--;
		}
	}
	int k = l-1;
	//swap a[k] and a[i]
	a[i-1] = a[k];
	a[k] = pivot;
	
	return k;
	
}

int rfr(int a[], int i, int j, int r)
{
	if(i>=j)
		return -1;
	int p = rand()%(j-i+1) + i;
	
	//swap a[i], a[p]
	int tmp = a[i];
	a[i] = a[p];
	a[p] = tmp;
	
	int k = partition(a, i+1, j, a[i]);
	
	if(k==r)
		return a[k];
	else if(k<r)
		return rfr(a, i, k-1, r);
	return rfr(a, k+1, j, r);
	
}
	
	
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n], i;
	scanf("%d", &a[0]);
	for(i=1; i<n; i++)
		scanf(" %d", &a[i]);
	int r = rfr(a, 0, n-1,k);
	
	if(r<0)
	{
		printf("Element not found\n");
		return 0;
	}
	printf("Rank = %d\n", r);
	return 0;
}
