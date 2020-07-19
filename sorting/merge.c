#include <stdio.h>
int count=0;
int merge(long int a[], int left, int middle, int right)	//To split and merge an array
{
	count++;
	int i, j, k;
	i = 0;
	j = 0;
	int n1 = middle-left+1;
	int n2 = right - middle;
	long int m[n1];
	long int n[n2];
	for (int t = 0; t<n1; t++)
		{m[t] = a[left+t];}

	for (int t=0; t<n2; t++)
		{n[t] = a[middle+1+t];}

	k = left;
	while(i<n1 && j<n2)					//Comparing the elements of 2 sorted arrays
	{
		if (m[i]<=n[j])
		{
			a[k] = m[i];
			i++;
		}
		else
		{
			a[k] = n[j];
			j++;
		}
		k++;
	}
	while (i<n1)						//If j goes out of bounds
	{
		a[k] = m[i];
		i++;
		k++;
	}
	while (j<n2)						//If i goes out of bounds
	{
		a[k] = n[j];
		j++;
		k++;
	}
						
}

int MergeSort(long int a[], int left, int right)		//Reccursive function
{
	if (right-left>0)
	{
		int middle =(right+left)/2;
		MergeSort(a, left, middle);
		MergeSort(a, middle+1, right);
		merge(a, left, middle, right);
		
	}
}	

int main()
{
	int n, i;
	scanf("%d", &n);					//Size of array
	long int a[n];
	scanf ("%ld", &a[0]);					//Taking 1st element of array as input
	for (i = 1; i<n; i++)					//Taking the rest of the elements of the array as input(separated by commas
		scanf (",%ld", &a[i]);
	MergeSort(a, 0, n-1);					//Sorting of the array

	printf ("%ld", a[0]);					//Printing the first element of the sorted array
	for (i=1; i<n; i++)					//Printing the other elements of the array separated by spaces (" ")
		printf (" %ld", a[i]);

	printf ("\n%d", count);				//Printing the number of times merge function is called
	return 0;
}
