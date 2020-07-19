#include <stdio.h>
void printa(int a[])
{
	int i=0;
	while(a[i])
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int a[] = {1,2,3,4};
	printf("%ld\n", sizeof(a)/sizeof(a[0]));
	printa(a);
	return 0;
}
