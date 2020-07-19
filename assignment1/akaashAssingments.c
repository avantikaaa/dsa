#include <stdio.h>
//#include<stdlib.h>
#include<string.h>

//WORKS
void buildST(int st[][26], char a[], int n, int p)
{
	int i, j;

	for (i=0; i<n; i++)
	{
		st[p+i-1][a[i]-97]++;
	}
	for(i=p-2; i>-1; i--)
	{
		for(j=0; j<26; j++)
		{
			st[i][j] = st[2*i + 1][j] + st[2*i + 2][j];
		}
	}

	return;
}

//WORKS
void update(int st[][26], char a[], int p, int k, char c)
{
	int prev = a[k]-97;
	int current = c - 97;
	int i=p+k;
	while(i>0)
	{
		st[i][prev]--;
		st[i][current]++;
		i = (i-1)/2;
	}
	st[0][prev]--;
	st[0][current]--;
	a[k] = c;
}

void buildFreq(int index, int freq[], char a[], int p, int st[][26])
{
	if(index<0)
		return;

	freq[a[index]-97]++;
	int i = p+index-1, parent;
//	printf("%d \n", i);
	while(i>0)
	{
		parent = (i-1)/2;
		if(i == 2*parent+2)		//Right child
		{
			for(int j=0; j<26; j++)
			{
				freq[j] += st[2*parent+1][j];
			}
		}
		i = (i-1)/2;
	}
}

int kSmallest(int st[][26], char a[], int k, int left, int right, int p)
{
	int freq1[26] = {0};
	int freq2[26] = {0};
	memset(freq1, 0, 26*sizeof(int));
	memset(freq2, 0 , 26*sizeof(int));

	buildFreq(left-1, freq1, a, p, st);
	buildFreq(right, freq2, a, p, st);
	
	int diff[26], i=0;
	for(i=0; i<26; i++)
		diff[i] = freq2[i] - freq1[i];

	int sum=0;
	i=0;
	while(sum<k && i<26)
	{
		sum += diff[i];
		i++;
	}

	if(sum>=k)
		return i-1;
	return -1;
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

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);

	int p = power(n);

	char a[n];
	scanf("%s", a);

	int st[26][2*p-1];
	memset(st, 0, sizeof(st));
	buildST(st, a, n, p);

	for(int i=0; i<q; i++)
	{
		int o;
		scanf("%d", &o);
		if(o==0)
		{
			int k;
			char c;
			scanf("%d %c", &k, &c);
			update(st, a, p, k-1, c);
		}
		else
		{
			int left, right, k;
			scanf("%d %d %d", &left, &right, &k);
			char resp = kSmallest(st, a, k, left-1, right-1, p);
			if(resp!=-1)
				printf("%c\n", resp+'a');
			else
				printf("Out of range\n");
		}
	}	
	return 0;
}
