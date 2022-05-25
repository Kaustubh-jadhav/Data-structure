#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct edge
{
    int ver;
    struct edge* next;
}* graph[MAX];

int n;
void create();
void addedge(int,int);
void display();
void degree();

void main()
{
    printf("\t Graph as adjecency list \n");
    create();
    display();
}

void create()
{
    printf("\n Enter number of vertex :");
    scanf("%d",&n);
    int t,h,i,j;
    do
    {
        printf("\n Enter vertex :");
        scanf("%d",&t);
        printf("\n Connected to :");
        scanf("%d",&h);
        addedge(t-1,h);
        addedge(h-1,t);
    }
    while(t>0 && h>0);
         printf("\n Graph Created Successfully");
    
}
void addedge(int i,int j)
{
     if(i>n || j>n)
        printf("\n Enter !!! invalid input");
     else if(i>-1 && j>-1)
     {
        struct edge *t,*temp=(struct edge*)malloc(sizeof(struct edge));
        temp->ver=j;
        temp->next=NULL;
        if(graph[i]==NULL)
           graph[i]=temp;
        else
        {
           t=graph[i];
           while(t->next != NULL)
                t=t->next;
           t->next=temp;
        }
     }
}
void display()
{
    struct edge *t;
    int i;
    printf("\n Adjecency Liste of graph\n vertex : edge");
    for(i=0;i<n;i++)
    {
        if(graph[i]==NULL)
            printf("\nNULL");
        printf("\n    %d---->",i+1);
        for(t=graph[i];t!=NULL;t=t->next)
        {
              printf("%d-->",t->ver);
              if(t->next==NULL)
                 printf("  NULL");
        }
        
    }
    degree();
}
void degree()
{
    struct edge *t;
    int i , j , e;
    printf("\n Degree : \n Vertex -Degree");
    for(i=0,e=0;i<n;i++,e=0)
    {
        printf("\n %d",i+1);
        for(j=0;j<n;j++)
        {
            for(t=graph[j];t!=NULL;t=t->next)
                if(t->ver==i+1 || j==i)
                   e++;
        }
        printf("%8d",e/2);
    }
    printf("\n");
}
/*[sy12@pc62 Sem 4]$ cc adj_list.c
[sy12@pc62 Sem 4]$ ./.out
bash: ./.out: No such file or directory
[sy12@pc62 Sem 4]$ ./a.out
	 Graph as adjecency list 

 Enter number of vertex :4

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

 Graph Created Successfully
 Adjecency Liste of graph
 vertex : edge
    1---->2-->3-->  NULL
    2---->1-->3-->4-->  NULL
    3---->1-->2-->4-->  NULL
    4---->2-->3-->  NULL
 Degree : 
 Vertex -Degree
 1       2
 2       3
 3       3
 4       2
[sy12@pc62 Sem 4]$ */
