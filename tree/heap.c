#include <stdio.h>

/*
DONE USING PRIORITY QUEUES.
	queue-> first in, first out
	stack -> first in,  last out
*/

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int min(int a, int b, int heap[])					//Not for finding minimum of 2 numbers
{
	if(heap[a]<heap[b])
		return a;
	return b;
}

//works
void bottomUp(int heap[], int i)				//Bottom-up heapify
{
	int p = (i-1)/2;
	while(heap[p]>heap[i] && p>=0)
	{
		swap(&heap[p], &heap[i]);
		
		i = p;
		p = (i-1)/2;
	}
}

//works
void topDown(int heap[], int i, int n)			//Top-down heapify
{
	while(2*i+2<n)
	{
		int l = min(2*i+1, 2*i+2, heap);
		if(heap[i]>heap[l])
			swap(&heap[i], &heap[l]);
		else 
			break;
		i = l;
	}
	if(2*i+1 <n && heap[i] >heap[2*i+1])
		swap(&heap[i], &heap[2*i+1]);
}

//works
void delete_min(int heap[], int n)				//Deleting the minimum node
{
	heap[0] = heap[--n];
	topDown(heap, 0, n);
}

//works
void insert(int heap[], int n, int i)				//Inserting a node
{
	heap[n] = i;
	bottomUp(heap, n++);
}

//works
void update(int heap[], int n, int i, int x)			//Updating a value of a node
{
	if(heap[i]<x)
	{
		heap[i] = x;
		topDown(heap, i, n);
	}
	else if(heap[i]>x)
	{
		heap[i] = x;
		bottomUp(heap, i);
	}
}

//works
void delete(int heap[], int n, int i)				//Deleting a particular node
{
	update(heap, n, i, heap[0]-1);
	delete_min(heap, n);
}

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	int heap[n];
		
	scanf("%d", &heap[0]);
	for(int i=1; i<n; i++)
		scanf(" %d", &heap[i]);
	
	print(heap, n);
	delete_min(heap, n);
	n--;
	print(heap, n);
	
	printf("insert: ");
	int tmp;
	scanf("%d", &tmp);
	insert(heap, n, tmp);
	n++;
	print(heap, n);
	
	printf("update: ");
	scanf("%d", &tmp);
	update(heap, n, 0, tmp);
	print(heap, n);
	
//Note to self: I am giving the index to be deleted. Not the user.
	delete(heap, n, 2);
	n--;
	print(heap, n);
	
	return 0;
}
