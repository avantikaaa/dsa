#include <stdio.h>

int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

int trap(int* height, int heightSize){
	int sum=0;
	int l, r, m1=0, m2=heightSize;
	for(int i=1; i<heightSize; i++)		//Main loop
	{
		if(*(height+m1)>*(height+i-1))
			l = m1;
		else
			l = i-1;
		m1 = l;
		if(i==1)
			for(int j=i+1; j<heightSize; j++)
				if(*(height+m2)<*(height+j))
					m2 = j;
		if(m2<=i)
		m2=i;
		{
			for(int j=i+1; j<heightSize; j++)
				if(*(height+m2)<*(height+j))
					m2 = j;
		}
		r=m2;
		if(min(*(height+l), *(height+r))>*(height+i))
		{
	//		printf("a %d
			sum+= min(*(height+l), *(height+r)) - *(height+i);
		}
printf("h-%d, l-%d, r-%d, sum-%d\n", *(height+i), *(height+l), *(height+r), sum);
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *ptr;
	scanf("%d", ptr);
	for(int i=1; i<n; i++)
		scanf(" %d", (ptr+i));
	printf("%d\n", trap(ptr, n));
	return 0;
}
