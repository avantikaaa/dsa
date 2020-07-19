#include <stdio.h>
void BubbleSort(long long int arr[22])			//Function for Bubble sort
{
	long long int tmp;				//Declaration of variables
	int i, swaps=0, comp=0;
	
	for (i=0; i<19; i++)				//Loop for comparing 2 values of the array
	{
		for (int j=0; j<19-i; j++)
		{
			comp++;
			if (arr[j]>arr[j+1])		//Swapping of 2 numbers
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				swaps++;
			}
		}
	}
	arr[20] = swaps;				//Number of swaps done while sorting
	arr[21] = comp;					//Number of comparisons
}
int main()
{
	long long int arr[22];
	scanf ("%lld", &arr[0]);			//Taking the array as an input where the elements are separated by commas(,)
	for (int j = 1; j<20; j++)
		scanf (",%lld", &arr[j]);
	BubbleSort(arr);				//Calling the sort function
	printf ("%lld", arr[0]);
	for (int i=1; i<20; i++)			//Printing the elements of the array separated by spaces
		printf (" %lld", arr[i]);
	printf ("\n%lld\n%lld\n", arr[20], arr[21]);	//Printing the number of swaps and comparisons
	return 0;
} 
