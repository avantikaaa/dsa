#include<stdio.h>
int rain(int n, int* arr);
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int water;
	water=rain(n, arr);
	printf("%d", water);
}


int rain(int n, int* arr)
{
	int min, area;
	int left[n];
	int right[n];
    int max=0;
	for(int p=0; p<n; p++)
    {
        if(arr[p]>max)
            max=arr[p];
        left[p]=max;
    }
    max=0;
    for(int q=n-1; q>=0; q--)
    {
        if(arr[q]>max)
            max=arr[q];
        right[q]=max;
    }
	area=0;
	for(int i=1; i<n-1; i++)
	{
		min=left[i];
		if(right[i]<min)
			min=right[i];
		area += min-arr[i];
	}
	return area;
}
