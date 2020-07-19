#include <stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int w;
    int index;
    struct node *next;
};

int search(int pq[], int n, int i, int v)
{
	if(i >= n)
		return -1;
	if(pq[i] == v)
		return i;
	if(pq[i] > v)
		return -1;
	int tmp = search(pq, n, 2*i+1, v);		//Search in the left
	if(tmp == -1)			//If v is not in the left child of the heap
		return search(pq, n, 2*n+2, v);		//Search in the right.
	return tmp;
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

int delete_min(int heap[], int *n)				//Deleting the minimum node
{
	int tmp = heap[0];
	heap[0] = heap[--(*n)];
	topDown(heap, 0, *n);
	return tmp;
}

void insert(int heap[], int n, int i)				//Inserting a node
{
	heap[n] = i;
	bottomUp(heap, n++);
	return search(heap, n, 0, i);
}

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

int dijkstra(struct node *adjList[], int n, int s, int v)
{
	int phi[n] = {-2};
	int V[n] = {0};				//Instead of boolean array, use 0's, 1's.
	int D[n] = {INT_MAX}; 	//The heap ig
	int heap[n];
	int pq[n], lenPQ = 0, u, index;						//Priority queue;
	
	D[s] = 0;
	pq[0] = u;
	while(lenPQ>0)
	{
		u = delete_min(pq, &lenPQ);
		V[u] = 1;
		struct node *ptr = adjList[u];
		while(ptr)
		{
			index = insert(
			if(V[ptr->v] == 0 && D[ptr->v] > D[u] + ptr->w)
			{
				update(pq, lenPq,, ptr->v, D[u]+ptr->w);
				phi[ptr->v] = u;
			}
		}
	}
	return getNodes(phi, u, v);
}

struct node *assign(int v, int w, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->v = v;
    ptr->w = w;
    ptr->index = index;
    return ptr;
}

int main()
{
    int n, p, m;
    scanf("%d %d %d", &n, &p, &m);
    struct node *adjList[n], *tmp;
    int i, u, v, w;
    for(i=0; i<p; i++)		//Converts edge list to adjecency list
    {
		scanf("%d %d %d", &u, &v, &w);
		tmp = assign(v, w, -1);
		tmp->next = adjList[u];
		adjList[u] = tmp;
    }

	for(i=0; i<m; i++)
	{
//		scanf("%d %d", &u, &v);
//		printf("%d\n", dijkstra(adjList, n, u, v));
	}

}

