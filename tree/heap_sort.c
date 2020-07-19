#include <stdio.h>

int min(int a, int b, int heap[])					//Not for finding minimum of 2 numbers
{
	if(heap[a]<heap[b])
		return a;
	return b;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

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

void insert(int heap[], int n, int i)				//Inserting a node
{
	heap[n] = i;
	bottomUp(heap, n++);
}

void build(int heap[], int n)				//looks like n*log(n) but is actually linear time.
{
	int tmp;
	scanf("%d", &heap[0]);
	for(int i=1; i<n; i++)
	{
		scanf(" %d", &tmp);
		insert(heap, i, tmp);
	}
}

void delete_min(int heap[], int n)			//log(n)
{
	swap(&heap[0], &heap[--n]);
	topDown(heap, 0, n);
}
	
void sort(int heap[], int n)				//n*log(n)
{
	for(int i=0; i<n; i++)
		delete_min(heap, n-i);
	for(int i=0; i<n/2; i++)				//n/2
		swap(&heap[i], &heap[n-i-1]);
}

void print(int arr[], int n)					//Linear time
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
	
	build(heap, n);						//n*log(n)
	print(heap, n);						//n
	sort(heap, n);						//n*log(n)
	print(heap, n);						//n
	
	return 0;
}
	
