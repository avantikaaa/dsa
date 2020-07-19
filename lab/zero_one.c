#include <stdio.h>
#include<string.h>
#include <math.h>

int longest(char arr[])
{
	int len = strlen(arr);
	int count = len, max=0;
	int t[len*2];
	memset(t, -1, 2*len*sizeof(int));
	
	t[count] = 0;

	for(int i=0; i<len; i++)
	{
		if(arr[i] == '1')
		{
			count++;
		}
		if(arr[i]=='0')
		{
			count--;
		}
		if(t[count]<0)
		{
			t[count] = i+1;
		}
		else
		{
			if(max<fabs(i-t[count]+1))
				max = fabs(i-t[count]+1);
		}
	}
	return max;
}
	
	

int main()
{
	char arr[100];
	scanf("%s", arr);
	
	int out = longest(arr);
	
	printf("%d\n", out);
	
	return 0;
}	
