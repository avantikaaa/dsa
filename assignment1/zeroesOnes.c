#include <stdio.h>
#include<string.h>

int power(int n)
{
	int out=1;
	while(n>0)
	{
		n /= 2;
		out *= 2;
	}
	return out;
}

void build(int st[], int n, int p)
{
//	int p = pow(n);
	int i=0;
	for(i=0; i<p; i++)
	{
		if(i<n)
			st[p+i-1] = 1;
		else
			st[p+i-1] = 0;
	}
	for(i=p-2; i>-1; i--)
		st[i] = st[2*i+1] + st[2*i+2];
	return;
}

void update(int st[], int n, int i)
{
	int k = n+i-1;
	if(st[k]==0)
		return;
//	st[n+i-1] = 0;
	while(k>0)
	{
		st[k]--;
		k = (k-1)/2;
	}
	st[0]--;
}

int  kIndex(int st[], int k, int l, int r, int root, int n)
{
	if(st[root]<k || l<0 || r>n-1)
		return -2;
	if(st[root]==k && l==r)
		return l;
	int m = (l+r)/2;
	int right = st[2*root+1];
	if(k>right)	//if k is less than left side
	{
		return kIndex(st, k-right, m+1, r, 2*root+2, n);
	}
	return kIndex(st, k, l, m, 2*root+1, n);
}

int main()
{
	int n;
	scanf("%d", &n);
	int p = power(n);
	int st[2*p-1];
	build(st, n, p);
	int qu;
	scanf("%d", &qu);
	for(int i=0; i<qu; i++)
	{
		int q, k;
		scanf("%d %d", &q, &k);
		if(q==0)
			update(st, p, k-1);
		else
			printf("%d\n", kIndex(st, k, 0, p-1, 0, p)+1);
	}
	return 0;
}
