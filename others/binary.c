#include<string.h>
#include<stdlib.h>
#include <stdio.h>
/*
Program prints the possible values of an 'n'-bit binary string.
*/

void binary(int n,char arr[])
{
  if(n < 1)
  {
    for(int i=0; i<strlen(arr); i++)
    	printf("%c", arr[i]);
    printf("\n");
  }
  else 
  {
    arr[n - 1] = '0';
    binary(n - 1,arr);
    arr[n - 1] = '1';
    binary(n - 1,arr);
  }
}





int main()
{
  int n;
  scanf("%d",&n);
  char arr[n];
  binary(n, arr);
  return 0;
}
