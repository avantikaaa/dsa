#include<stdio.h>
#include<stdlib.h>
int* path(int label, int* returnSize);
int main()
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr=path(n, arr);
	int l=0, k=1;
    	while(k<n)
    	{
    		l++;
        	k*=2;
    	}
	for(int i=0; i<l; i++)
	{
		printf("%d ", arr[i]);
	}
}

int* path(int label, int* returnSize)
{
	int l=0, k=1;
    	while(k<label)
    	{
        	l++;
        	k*=2;
    	}
    	returnSize=(int*)malloc(l*sizeof(int));
    	l--; k/=2;
    	while(label>=1)
    	{
        	returnSize[l]=label;
        label=(3*k-label-1)/2;
        l--;k/=2;
    }
    return returnSize;
}
