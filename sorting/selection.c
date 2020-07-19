#include <stdio.h>
int SelectionSort(long long int a[22])		//Function
{
	int index, swaps=0, comp=0;
	long long int tmp;
	for (int i=0; i<19; i++)
	{
		index = i;
		for (int j=i+1; j<20; j++)
		{
			comp++;			//Number of comparisons
			if (a[j]<a[index])	//Indexing the smallest element
				index = j;
		}
		tmp = a[index];			//Swapping of elements
		a[index] = a[i];
		a[i] = tmp;
		swaps++;			//Number of swaps done
	}
	a[20] = swaps;
	a[21] = comp;
}
int main()
{
	long long int a[22];
	int i;
	scanf ("%lld", &a[0]);			//Taking the first element of the array as an input
	for (i = 1; i<20; i++)			//Taking the other elements of the array as input separated by a comma(,)
		scanf (",%lld", &a[i]);
	SelectionSort(a);			//Sorting of the array
	printf ("%lld", a[0]);			//Printing the first element of the array
	for (i=1; i<20; i++)
		printf (" %lld", a[i]);		//Printing the other elements of the array separated by space(" ")
	printf ("\n%lld %lld\n", a[20], a[21]);	//Prints the number of swaps and comparisons made in the next line
	return 0;
}
