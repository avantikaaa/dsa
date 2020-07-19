#include <stdio.h>
#include<limits.h>

struct segment{
	int min;
	int max;
};

int maximum(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int minimum(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

void update(struct segment st[], int a[], int n, int i, int val)
{
	a[i] = val;
	st[n+i-1].min = val;
	st[n+i-1].max = val;
	
	i = (n+i-2)/2;
	while(i>=0)
	{
		st[i].min = minimum(st[2*i+1].min, st[i*2+2].min);
		st[i].max = maximum(st[2*i+1].max, st[2*i+2].max);
		
		if(i==0)
			break;
		i = (i-1)/2;
	}
}

int findmax(struct segment st[], int n, int i, int j, int s, int e, int p)
{
    if (s > j || e < i)
        return INT_MIN;
    else if (s >= i && e <= j)
        return st[p].max;

    int mid = (s+e)/2;

    return maximum(findmax(st,n,i,j,s,mid,2*p+1), findmax(st,n,i,j,mid+1,e,2*p+2));
}

int findmin(struct segment st[], int n, int i, int j, int s, int e, int p)
{
    if (s > j || e < i)
        return INT_MAX;
    else if (s >= i && e <= j)
        return st[p].min;

    int mid = (s+e)/2;

    return minimum(findmin(st,n,i,j,s,mid,2*p+1), findmin(st,n,i,j,mid+1,e,2*p+2));
}

int query(struct segment st[], int n, int x, int c)
{
    int s = 1, e = n-x;
    int mid, flag;
    while(s < e)
    {
        mid = (s + e)/2;
        int max = findmax(st,n,x,x+mid-1,0,n-1,0);
        int min = findmin(st,n,x,x+mid-1,0,n-1,0);
        if(st[n+x-1].min - c <= min && max <= st[n+x-1].max + c)
        {
            s = mid + 1;
            flag = 1;
        }
        else
        {
            e = mid;
            flag = 0;
        }
    }
    if(flag)
        return mid;
    return mid-1;
}

int findZ(struct segment st[], int n, int x, int len)
{
	int max = findmax(st, n, x, x+len-1, 0, n-1, 0);
	int min = findmin(st, n, x, x+len-1, 0, n-1, 0);
	return maximum(max-st[n+x-1].max, st[n+x-1].min-max);
}

void build(struct segment st[], int a[], int n, int p)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(i<p)
		{
			st[n+i-1].min = a[i];
			st[n+i-1].max = a[i];
		}
		else
		{
			st[n+i-1].min = INT_MIN;
			st[n+i-1].max = INT_MAX;
		}
	}
	for(i=n-2; i>=0; i--)
	{
		st[i].min = minimum(st[2*i+1].min, st[2*i+2].min);
		st[i].max = maximum(st[2*i+1].max, st[2*i+2].max);
	}
}

int power(int n)
{
	int out = 1;
	while(out<n)
	{
		out *= 2;
	}
	return out;
}


int findN(int n){
    long long int power=1;
    for(int i=1; ;i++){
        power *=2;
        if(power>=n)
            return power;
    }
}


int main()
{
	int p, t;
	scanf("%d %d", &p, &t);
	
	int a[p], i;
	for (i=0; i<p; i++)
		scanf("%d", &a[i]);
	
	long long int n = findN(p);
	struct segment st[2*n-1];
	build(st, a, n, p);
	
/*	for(i=0; i<2*n-1; i++)
		printf("%d ", st[i].min);
	printf("\n");
	for(i=0; i<2*n-1; i++)
		printf("%d ", st[i].max);
	printf("\n");*/
	
	char q;
	int x, y, c;	
	while(t>0)
	{
		scanf("\n%c", &q);
		if(q=='U')
		{
			scanf("%d %d", &x, &y);
			update(st, a, n, x-1, y);
		}
		else if (q=='Q')
		{
			scanf("%d %d", &x, &c);
			if(c<0)
				printf("-1 -1\n");
			else
			{
				int len = query(st, n, x-1, c);
				int z = findZ(st, n, x-1, len);
				printf("%d %d\n", len, z);
			}
		}
		t--;
	}
	
	return 0;
}
