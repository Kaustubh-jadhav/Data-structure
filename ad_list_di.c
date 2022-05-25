
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct edge
{
	int vert;
	struct edge* next;
}* graph[MAX];

int n;

void create();
void addedge(int,int);
void display();
void degrees();

void main()
{
	printf("\nGraph as Adjacency List\n");
	create();
	display();
}

void create()
{
	printf("\nCreating Graph");
	printf("\nEnter Number of vertices :");
	scanf("%d",&n);
	int t,h,i,j;
	do
	{       
	   printf("\n Enter vertex :");
	   scanf("%d", &t);
       printf("\n Connected to :");
       scanf("%d", &h);
	   addedge(t-1,h);
	}
	while(t>0 && h>0);
	     printf("\nGraph Created Successfully.");
}

void addedge(int i, int j)
{
	if(i>n || j>n)
		printf("\nError!!! Invalid Input.");
	else if(i>-1 && j>-1)
	{
		struct edge *t,*temp=(struct edge*)malloc(sizeof(struct edge));
		temp->vert = j;
		temp->next  = NULL;
		if(graph[i] == NULL)
			graph[i]=temp;
		else
		{
			t=graph[i];
			while(t->next!=NULL)
				t=t->next;
			t->next=temp;
		}
	}
}

void display()
{
	struct edge *t;
	int i;
	printf("\nAdjecency list for graph\nVertex : Edges");
	for(i=0;i<n;i++)
	{
		printf("\n  %d   -->", i+1);
		for(t=graph[i];t!=NULL;t=t->next)
		{
			printf(" %d -->", t->vert);
			if(t->next==NULL)
				printf(" NULL");
		}
	}
	degrees();
        
}

void degrees()
{
     struct edge *t;
     int id, i,j,od;
     printf("\n Degrees:\nVertex - Indegrees    Outdegrees   totaldegree");
	for(i=0,id=0,od=0;i<n;i++,od=0,id=0)
	{
	    printf("\n  %d   ",i+1);
	    for(j=0;j<n;j++)
	    {
		for(t=graph[j];t!=NULL;t=t->next)
	        {
		    if(t->vert==i+1)
			id++;
	            if(j==i)
			od++;
		}
	    }
		printf("%8d %10d %10d", id,od,id+od);
	}
        printf("\n");
}
/*[sy12@pc62 Sem 4]$ cc ad_list_di.c
[sy12@pc62 Sem 4]$ ./a.out

Graph as Adjacency List

Creating Graph
Enter Number of vertices :4

 Enter vertex :1

 Connected to :2

 Enter vertex :1

 Connected to :3

 Enter vertex :2

 Connected to :3

 Enter vertex :2

 Connected to :4

 Enter vertex :3

 Connected to :4

 Enter vertex :0

 Connected to :0

Graph Created Successfully.
Adjecency list for graph
Vertex : Edges
  1   --> 2 --> 3 --> NULL
  2   --> 3 --> 4 --> NULL
  3   --> 4 --> NULL
  4   --> NULL
 Degrees:
Vertex - Indegrees    Outdegrees   totaldegree
  1          0          2          2
  2          1          2          3
  3          2          1          3
  4          2          0          2
[sy12@pc62 Sem 4]$ 
*/ 
      
      
      
      
