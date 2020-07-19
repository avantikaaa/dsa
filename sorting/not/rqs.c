#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

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

/*
printf("before-> ");
	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
	printf("\n");
*/
	
	a[i-1] = a[k];
	a[k] = pivot;
//	swap(&a[k], &a[i-1]);
/*	
printf("%d %d %d\nafter-> ", k, i-1, pivot);
	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
	printf("\n");
*/
	
	return k;
	
}

void rqs(int a[], int i, int j)
{
	if(i>=j)
		return;
	
	int p = rand()%(j-i+1) + i;
/*
printf("p-%d a[p]%d\nArray->", p, a[p]);
	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
	printf("\n");
*/
	//swap
	int tmp = a[p];
	a[p] = a[i];
	a[i] = tmp;
	
	int k = partition(a, i+1, j, a[i]);
	rqs(a, i, k-1);
	rqs(a, k+1, j);
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	scanf("%d", &a[0]);
	for(int i=1; i<n; i++)
		scanf(" %d", &a[i]);
	rqs(a, 0, n-1);
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
