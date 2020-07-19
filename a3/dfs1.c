#include <stdio.h>
#include<stdlib.h>

struct List{
    int v;
    int w;
    struct node *next;
};

int dfs(struct List *list[], int s, int n, int t)
{
	int v[n] = {0};
	int phi[n] = {-2};
	int i;
	struct List *head = (struct List*)malloc(sizeof(struct List));
	head->v = s;
	struct List *tmp, t1, h1;
	while (head)
	{
		if(v[head->v] == 0)
		{
			v[head->v] = 1;
			tmp = list[head->v];
			if(tmp)
			{
				h1 = head;
				head = head->next;
				while(tmp)
				{
					if(v[tmp->v] == 0)
					{
						head = assign(tmp->v, tmp->w);
						phi[head->v] = h1->v;
					}
					tmp = tmp->next;
				}
			}
			else
				head = head->next;
		}
		else
			head = head->next;
	}
	int count = 0;
	while(t != s)
}

struct List *assign(int v, int w)
{
    struct List *ptr = (struct List *)malloc(sizeof(struct List));
    ptr->v = v;
    ptr->w = w;
    return ptr;
}

int main()
{
    int n, p, m;
    scanf("%d %d %d", &n, &p, &m);
    struct List *list[n], *tmp;
    int i, u, v, w;
    for(i=0; i<p; i++)		//Converts edge list to adjecency list
    {
		scanf("%d %d %d", &u, &v, &w);
		tmp = assign(v, w);
		tmp->next = list[u];
		list[u] = tmp;
    }

	for(i=0; i<m; i++)
	{
//		scanf("%d %d", &u, &v);
//		printf("%d\n", dijkstra(adjList, n, u, v));
	}

}

