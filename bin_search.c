#include <stdio.h>
//#include<string.h>
#include<stdlib.h>

int bin_search(int ar[], int l, int r, int num, int n)	//Function works only for array sorted in ascending order
{
	if(l>=r)
		return n+1;
	int m = (l+r)/2;
	if(num==ar[m])
		return m;
	if(num>ar[m])
		return bin_search(ar, m+1, r, num, n);
	return bin_search(ar, l, m, num, n);
}

void bubble(int ar[], int n)
{
//	int n = intlen(ar);
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
		{
			if(ar[j]>ar[j+1])
			{
				int tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
}

int main()
{
	int n, k;
	printf("Enter number of elements in the array: ");
	scanf("%d", &n);
	int ar[n];
	for(int i=0; i<n; i++)
		scanf("%d", &ar[i]);
	bubble(ar, n);


printf("The array after sorting:");
for (int i=0; i<n; i++)
	printf(" %d", ar[i]);
printf("\n");


	printf("Enter number to be searched: ");
	scanf("%d", &k);
	k = bin_search(ar, 0, n, k, n);
	if(k==n+1)
		printf("The number is not present in the given array\n");
	else
		printf("The number is present at index %d after sorting\n", k);
	return 0;
}


/*
you have an array of integers
you have to tell whether there exists a sub array which has the sum of elements equal to a given number 'k'
sub-array-> continuous elements of the main array.
*/

















