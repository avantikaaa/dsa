/*
Pivot is not chosen randomly.
*/
#include <stdio.h>

void QuickSort(long int a[], int left, int right)	//Reccursive function to keep repeating the above function until the array is sorted
{
	if (left < right)
	{
		long int pivot, tmp;     
		int i;
		i = left-1;
		pivot = right;
		for (int j = left; j < right; j++)	//Compares the value of the element with the pivot element
		{
			if (a[j] < a[pivot])		//Swapping of the elements
			{
				i++;  
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
        		} 
    		}  
		pivot = i+1;				//New index of the pivot element
		tmp = a[pivot];				//Swapping the pivot element with the element in its new index
   		a[pivot] = a[right];
    		a[right] = tmp;
		QuickSort(a, left, pivot - 1);		//Sorting the left side of the array with respect to the new index of the pivot
		QuickSort(a, pivot + 1, right);		//Sorting the right side of the array with respect to the new index of the pivot
	} 
} 
  

int main()
{
	int i, n, m;
	scanf ("%d\n", &n);				//Number of elements in the array
	long int a[n], last;
	scanf ("%ld", &a[0]);				//Taking the first element of the array as an input
	for (i = 1; i<n; i++)				//Taking the other elements of the array as input separated by a comma(,)
		scanf (",%ld", &a[i]);			//Sorting of the array
	last = a[n-1];
	QuickSort(a, 0, n-1);				
	for (i=0; i<n; i++)				//For the new index of the last element of the array taken as input
	{
		if(last == a[i])
		{	m = i;
			break;
		}
	}
	printf ("%ld", a[0]);				//Printing the first element of the array
	for (i=1; i<n; i++)				//Printing the other elements separated by space(" ")
		printf (" %ld", a[i]);
	printf ("\n%d", m);				//Printing the new index of the last element of the array taken as input
	return 0; 
} 
