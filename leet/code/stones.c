#include<stdio.h>

int last(int* stones, int* n);
void build_max(int* H, int n);
int deletemax(int* H, int* n);
void topdown_max(int* H, int n, int i);
void add_max(int* H, int* n, int x);
void bottomup_max(int* H, int i);
void swap(int * a, int *b);

int main()
{
	int n;
	int weight;
	scanf("%d", &n);
	int stones[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &stones[i]);
	}
	weight=last(stones, &n);
	printf("%d", weight);
}

int last(int* stones, int* n)
{
	build_max(stones, *n);
	while(*n>1)
	{
		int max1 = deletemax(stones, n);
		int max2 = deletemax(stones, n);
		if(max1-max2>0)
		{
			add_max(stones, n, max1-max2);
		}
	}
	if(*n==1)
		return stones[0];
	else
		return 0;
}

void build_max(int* H, int n)  //max
{
	for(int i=n/2; i>=0; i--)
	{
		topdown_max(H, n, i);
	}
}

int deletemax(int* H, int* n)  //max
{
	int max = H[0];
	H[0]=H[(*n)-1];
	(*n)--;
	topdown_max(H, *n,0);
	return max;
}

void topdown_max(int* H, int n, int i)  //max
{
	int l;
	while(2*i+2<n)
	{
		if(H[2*i+1]>H[2*i+2])
			l=2*i+1;
		else
			l=2*i+2;
		if(H[i]<H[l])
		{
			swap(&H[i], &H[l]);
			i=l;
		}
		else
			break;
	}
	if((2*i+1<n) && H[i]<H[2*i+1])
	{
		swap(&H[i], &H[2*i+1]);
	}
}

void add_max(int* H, int* n, int x)  //max
{
	H[*n]=x;
	(*n)++;
	bottomup_max(H, (*n)-1);
}

void bottomup_max(int* H, int i) //max
{
	int p;
	p = (i-1)/2;
	while((p>=0) && (H[p]<H[i]))
	{
		swap(&H[p], &H[i]);
		i=p;
		p=(i-1)/2;
	}
}

void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
