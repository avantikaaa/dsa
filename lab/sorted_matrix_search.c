/*
Given :- Sorted matrix(n*m), that is, a(i, j)<a(i, j+1) and a(i, j)<a(i+1, j)
RTF    :- Whether a given number 'k' is present in the matrix.
*/
#include <stdio.h>
#include<stdbool.h>

/*
i, j- index of the element we are comparing.
m- number of coloumns
k-number we have to look for.
*/
bool find(int out[], int i, int j, int m, int k, int a[][m])
{
	if(j==m)
		return false;
	if(a[i][j]==k)
	{
		out[0] = i;
		out[1] = j;
		return true;
	}
	if(a[i][j]>k)
		return find(out, i-1, j, m, k, a);
	return find(out, i, j+1, m, k, a);
}

int main()
{
	int n, m;
	printf("Dimensions: ");
	scanf("%d %d", &n, &m);
	int k;
	printf("Number: ");
	scanf("%d", &k);
	int a[n][m];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i][0]);
		for(int j=1; j<m; j++)
			scanf(" %d", &a[i][j]);
	}
	int out[2];
	bool ans = find(out, n-1, 0, m, k, a);
	if(ans==true)
		printf("Yes, at index i=%d and j=%d\n", out[0], out[1]);
	else
		printf("No\n");
	return 0;
}
