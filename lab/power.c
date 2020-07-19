#include<stdio.h>

int power(int n, int k) 
{ 
    if (k == 0) 
        return 1; 
    else if (k%2 == 0) 
        return power(n, k/2)*power(n, k/2); 
    else
        return n*power(n, k/2)*power(n, k/2); 
}

int power1(int n, int k)
{
	int x=n;
	while(k!=0)
	{
printf("x-%d n-%d  ", x, n);
		if(k%2==0)
			x = x*n;
			
		else
		{
			n = n*x;
			x *= x;
		}
		k = k/2;
	}
printf("\n");
	return x;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d %d\n", power(n, k), power1(n,k));
	return 0;
}
