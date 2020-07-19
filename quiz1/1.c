#include <stdio.h>
#include<string.h>
/*
Done by using the count sort algorithm.
*/
int count(int a[], int min, int max, int n, int T)
{
	int c[max-min+1];
	memset(c, 0, (max-min+1)*sizeof(int));	//Initialising all elements to 0.
	//Sum upto that index
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

int main()
{
	int n, T;
	scanf("%d %d", &n, &T);
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
	
	int out = count(a, min, max, n, T);
	
//	for(int i=0; i<n; i++)
//		printf("%d ", a[i]);
	printf("%d\n", out);
	
	return 0;
}
