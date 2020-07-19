#include <stdio.h>
#include<string.h>
/*
Done by using the count sort algorithm.
binary search over the answer.
*/
int count(int a[], int min, int max, int n, int T)
{
	int c[max-min+1];
	memset(c, 0, (max-min+1)*sizeof(int));
	
	for(int i=0; i<n; i++)				//1 loop of order n
		c[a[i]-min]++;
	int p[max-min+1];
	
	p[0] = c[0];
	for(int i=1; i<max-min+1; i++)		//1 loop of order max-min+1 	worst case- order n+c
		p[i] = p[i-1]+c[i];

	int sum = 0;
	int j = max-min;			//Calculates number of good pairs.
	while(j>T)						//Loop of order max-min+1-T	worst case order n+c
	{
		sum += p[j-T-1];
		j--;
		while(c[j]==0)
			j--;
	}



	return sum;
}

/*
Binary search over answer.
Worst case-
	(max-min)*log(max-min)
*/
int bin(int a[], int min, int max, int n, int k, int t1, int t2)
{
	if(t1>=t2)
	{
//printf("%d %d\n", t1, t2);
		return t2;
	}
	int mid = (t1+t2)/2;
	int out = count(a, min, max, n, mid);
	if(out==k)
	{
		if(count(a, min, max, n, mid-1)==k)
			return bin(a, min, max, n, k, t1, mid-1);
		return mid;
	}
	if(out<k)
	{
//printf("a. %d %d\n", t1, t2);
		return bin(a, min, max, n, k, t1, mid-1);
	}
//printf("b. %d %d\n", t1, t2);
	return bin(a, min, max, n, k, mid+1, t2);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	scanf("%d", &a[0]);
	int max = a[0], min = a[0];
	for(int i=1; i<n; i++)
	{
		scanf(" %d", &a[i]);
		if(max<a[i])
			max = a[i];
		if(min>a[i])
			min = a[i];
	}
	
	int out = bin(a, min, max, n, k, 0, max-min);

	printf("%d\n", out);
	
	return 0;
}
