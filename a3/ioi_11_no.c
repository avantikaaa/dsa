#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

struct List{
	long long int i;
	long long int w;
	struct List *next;
};

struct List *mst[100000];
bool visited[100000] = {false};
long long int result[1010][1010];

struct List *assign(struct List *node, long long int i, long long int w)
{
	struct List *ptr = (struct List*)malloc(sizeof(struct List));
	ptr->i = i;
	ptr->w = w;
	ptr->next = node;
	return ptr;
}

void swap(long long int *a, long long int *b)
{
	long long int tmp = *a;
	*a = *b;
	*b = tmp;
}

void topDown(long long int H[], long long int A[], long long int B[], long long int i, long long int n)
{
	long long int c, tmp;
	while(2*i + 2 < n)
	{
		if(H[2*i+1] < H[2*i+2])
			c = 2*i + 2;
		else
			c = 2*i + 1;
		if(H[i] > H[c])
		{
			swap(&H[i], &H[c]);
			swap(&A[i], &A[c]);

			B[A[c]] = c;
			B[A[i]] = i;
		}
		else
			i = n;
	}
	c = 2*i + 1;
	if(c < n && H[i] > H[c])
	{
		swap(&H[i], &H[c]);
		swap(&A[i], &A[c]);

		B[A[c]] = c;
		B[A[i]] = i;
		i = c;
	}
}

void bottomUp(long long int H[], long long int A[], long long int B[], long long int i)
{
	long long int p = (i-1) / 2, tmp;
	while(p > -1)
	{
		if(H[i] <H[p])
		{
			swap(&H[i], &H[p]);
			swap(&A[i], &A[p]);

			B[A[i]] = i;
			B[A[p]] = p;
			
			i = p;
			p = (i-1) / 2;
		}
		else
			break;
	}
}

void deleteMin(long long int H[], long long int A[], long long int  B[], long long int *n)
{
	long long int tmp;
	*n = *n - 1;
	
	swap(&H[0], &H[*n]);
	swap(&A[0], &A[*n]);

	B[A[0]] = 0;
	B[A[*n]] = *n;
	
	topDown(H, A, B, 0, *n);
}

void decreaseKey(long long int H[], long long int A[], long long int B[], long long int i, long long int x)
{
	H[i] = x;
	bottomUp(H, A, B, i);
}

void DFS(long long int s, long long int org, long long int tot)
{
	result[org][s] = tot;
	visited[s] = true;
	struct List *tmp = mst[s];
	while(tmp)
	{
		if(!visited[tmp->i])
		{
			DFS(tmp->i, org, tot+tmp->w);
		}
		tmp = tmp->next;
	}
}

void PrimsMin(struct List *list[], long long int s, long long int n)
{
	long long int A[100000], B[100000], H[100000], phi[n], i, u, v, m=n;
	struct List *node;
	bool V[n];
	for(i=0; i<n; i++)
	{
		phi[i] = -2;
		H[i] = INT_MAX;
		A[i] = i;
		B[i] = i;
		V[i] = false;
		mst[i] = NULL;
	}
	
	H[0] = 0;
	phi[s] = -1;
	A[0] = s;
	A[s] = 0;
	B[0] = s;
	B[s] = 0;
	
	for(i=0; i<n && H[0]<INT_MAX; i++)
	{
		u = A[0];
		V[u] =true;
		node = list[u];
		deleteMin(H, A, B, &m);
		while(node)
		{
			v = node->i;
			if(!V[v] && H[B[v]] > node->w)
			{
				decreaseKey(H, A, B, B[v], node->w);
				phi[v] = u;
			}
			node = node->next;
		}
	}
	for(i=0; i<n; i++)
	{
		mst[i] = assign(mst[i], phi[i], H[B[i]]);
		mst[phi[i]] = assign(mst[phi[i]], i, H[B[i]]);
	}
}


int main()
{
	long long int cases, c;
	scanf("%lld", &cases);

	for(c = 1; c <= cases; c++)
	{
		long long int n, p, m, i;
		scanf("%lld %lld %lld", &n, &p, &m);
		struct List *list[n];
		
		for(i=0; i<n; i++)
			list[i] = NULL;
		
		for(i = 0; i < p; i++)
		{
			long long int u, v, d;
			scanf("%lld %lld %lld", &u, &v, &d);
			list[u-1] = assign(list[u-1], v-1, d);
			list[v-1] = assign(list[v-1], u-1, d);
		}
		PrimsMin(list, 0, n);
		for(i=0; i<n; i++)
		{
			memset(visited, false, n);
			DFS(i, i, 0);
		}
		printf("Case: %lld\n", c);
		for(i=0; i<m; i++)
		{
			long long int u, v;
			scanf("%lld %lld", &u, &v);
			printf("%lld\n", result[u-1][v-1]);
		}
	} 
	
	return 0;
}

