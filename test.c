#include<stdio.h>

int main()
{
	int *ptr, **pptr, i;
	for(i=0; i<5; i++)
		*(ptr+i) = i+1;
	int n;
	scanf("%d", &n);
	for(i=0; i<5; i++)
		if(*(ptr+i) == n)
		{
			*pptr = (ptr+i);
			*pptr = (ptr+i+1);
			break;
		}
	while(ptr)
	{
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");
	return 0;
}
