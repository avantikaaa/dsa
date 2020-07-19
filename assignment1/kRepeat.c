#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int freq;
	int index;
	struct node *next;
};

struct point{
	struct node *a;
};

int compareString(char s[], int index1, int index2, int len)
{
	for(int i=0; i<len; i++)
		if(s[index1+i] != s[index2+i])
			return 0;
	return 1;
}

int makehash(char s[],int n,int mid,int k){
    struct node* tmp;
    tmp= (struct node*) malloc(sizeof(struct node));

    struct point ht[n-mid+1];
    for(int i=0; i<n-mid+1 ;i++){
        ht[i].a  = NULL;
        ht[i].a  = (struct node*)malloc(sizeof(struct node));
        ht[i].a->freq = 0;
        ht[i].a->index = 0;
    }

    int hash=0,index;
    for(int i=0;i<mid;i++)
        hash += (int)s[i];
    index = hash%(n-mid+1);

    if(ht[index].a->freq==0)
    {
        ht[index].a->freq = 1;
        ht[index].a->index =0;
        ht[index].a->next = NULL;
    }

    for(int i=1;i<n-mid+1;i++)
    {
        hash = hash + (int)s[mid+i-1] - (int)s[i-1];
        index = hash%(n-mid+1);

        if(ht[index].a->freq == 0)
        {
            ht[index].a->freq = 1;
            ht[index].a->index =i;
            ht[index].a->next = NULL;
        }

        //if node is already present
        else if(ht[index].a != NULL)
        {
            tmp=ht[index].a;

            while(tmp != NULL)
            {
                if(compareString(s,i,tmp->index,mid))
                {
                    tmp->freq++;
                    break;
                }
                if(tmp->next==NULL)
                {
                    struct node* new_node;
                    new_node= (struct node*) malloc(sizeof(struct node));
                    new_node->freq = 1;
                    new_node->index = i;
                    new_node->next = NULL;
                    tmp->next = new_node;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }

    int max=0;
    for(int i=0;i<n-mid+1;i++)
    {
        tmp = ht[i].a;
        if(tmp->freq != 0)
        {
            while(tmp != NULL)
            {
                if(tmp->freq>=k)
                        max=1;
                tmp=tmp->next;
            }
        }
    }

    //freeing memory allocted to pointers
    for(int i=0; i<n-mid+1;i++)
        free(ht[i].a);

    // returning value of max
    return max;
}


int binSearch(char s[], int len, int k)
{
    int first =0,last=len,l,mid,maxLen=1;
    while(first<=last)
    {
		mid = (first + last)/2;
		// if we get a substring which repeats atleast k times
		if(makehash(s,len,mid,k))
		{
			//we to check a substring of higher length
			first = mid + 1 ;
			if(maxLen<mid)
				maxLen = mid ;
        }
		//else we to check a substring of lesser length
		else
			last = mid - 1 ;
    }
    
    return maxLen;
}

int main()
{
	char s[100000];
	int k;
	scanf("%s", s);
	scanf("%d", &k);
	int len = strlen(s);
	
	printf("%d\n", binSearch(s, len, k));

	return 0;
}
