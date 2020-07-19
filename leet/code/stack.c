#include<stdio.h>
int stack(int* pushed, int* popped, int n);
int main()
{
	int n;
	scanf("%d", &n);
	int pushed[n];
	int popped[n];
	int b;
	for(int i=0; i<n; i++)
		scanf("%d", &pushed[i]);
	for(int i=0; i<n; i++)
                scanf("%d", &popped[i]);
	b=stack(pushed, popped, n);
	if(b==1)
		printf("true");
	else if(b==0)
		printf("false");
}

int stack (int* pushed, int* popped, int n)
{
	int S[n];
	int top, i, j;
	top=-1; i=0; j=0;
	while(i<n)
	{
		top++;
		S[top]=pushed[i];
		while((j<n)&&(S[top]==popped[j]))
		{
			top--;
			j++;
		}
		i++;
	}
	if (top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
