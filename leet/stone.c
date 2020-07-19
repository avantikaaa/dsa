#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//changed
int max(int a, int b, int *heap)					//Not for finding minimum of 2 numbers
{
	if(heap[a]>heap[b])
		return a;
	return b;
}
void bottomUp(int *heap, int i)
{
	int p = (i-1)/2;
	while(*(heap+p)<*(heap+i) && p>=0)
	{
		swap(heap+p, heap+i);
		i=p;
		p=(i-1)/2;
	}
}

void topDown(int *heap, int n, int i)
{
	while(2*i+2<n)
	{
		int l=max(2*i+1, 2*i+2, heap);
		if(*(heap+i)<*(heap+l))
			swap(heap+i, heap+l);
		else
			break;
		i=l;
	}
	if(2*i+1<n && *(heap+i)<*(heap+2*i+1))
		swap(heap+i, heap+2*i+1);
}
void update(int *heap, int n, int i, int x)
{
	if(*(heap+i)<x)
	{
		*(heap+i)=x;
		bottomUp(heap, i);
	}
	else
	{
		*(heap+i)=x;
		topDown(heap, n, i);
	}
}

void delete_max(int *heap, int n)
{
	*heap=*(heap+n-1);
	topDown(heap, n, 0);
}

void insert(int *heap, int n, int i)
{
	*(heap+n) = i;
	bottomUp(heap, n);
}

void build(int *heap, int n)
{
	for(int i=1; i<n; i++)
	{
		insert(heap, i, *(heap+i));
	}
}

void print(int *heap, int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", *(heap+i));
	printf("\n");
}

int lastStoneWeight(int* heap, int n){
    //make a max heap
    build(heap, n);
//print(heap, n);
	while(n>1)
	{
		if(n>2)
		{
			int l = max(1, 2, heap);
			int diff = *heap- *(heap+l);
			if(diff>0)
			{
//printf("k %d %d\n", *(heap+l), *heap);
				update(heap, n, l, diff);
				delete_max(heap, n);
			}
			else			//diff ==0
			{
			//	printf
				delete_max(heap, n);
				n--;
				delete_max(heap, n);
			}
			n--;
		}
		else if(n==2)
		{
			int diff = *(heap)-*(heap+1);
//	printf("afdk %d %d %d\n", diff, *heap, *(heap+1));
          		return diff;
		}
	}
    return *heap;
}



int main()			//driver function.
{
	int n;
	scanf("%d", &n);
	int *heap;
	scanf("%d", heap);
	for(int i=1; i<n; i++)
		scanf(" %d", heap+i);
	printf("%d\n", lastStoneWeight(heap, n));
	return 0;
}
