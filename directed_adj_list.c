#include<stdio.h>
#include<stdlib.h>
#define N 10
int n,a[N][N];
struct node
{
     int vertex;
     struct ll *edge;
}*list[10];

void adjlist(int a[10][10],int n)
{
     int i ,j;
     struct node *temp,*newnode;
     for(i=0;i<n;i++)
     {
         list[10];
         for(j=0;j<n;j++)
         {
             newnode=malloc(sizeof(struct node));
             newnode=a[j];
             newnode->vertex=j+1;
             newnode->edge=NULL;
             if(list[i]==NULL)
                list[i]=temp=newnode;
             else
             {
                temp->edge=newnode;
                temp=newnode;
                list[i]=temp;
             }
         }
     }
}
void readgraph()
{
     int i,edge,start,stop;
     printf("\n Enter Number of vertices :");
     scanf("%d",&n);
     edge=n*(n-1);
     for(i=1;i<=edge;i++)
     {
          printf("\n Enter vertex =");
          scanf("%d",&start);
          printf(" connected to =");
          scanf("%d",&stop);
          if(start==0 && stop==0)
             break;
          if(start>n||stop>n||start<=0||stop<=0)
          {
              printf("\n Invalid edge");
              i--;
          }
          else 
              a[start][stop]=1;
       }
       adjlist(a,n);
       

}
int getoutdegree(int k)
{
    int j , d=0;
    for(j=1;j<=n;j++)
        if(a[k][j]==1)
           d++;
    return d;
}
int getindegree(int k)
{
    int j,d=0;
    for(j=1;j<=n;j++)
       if(a[j][k]==1)
         d++;
    return d;
}
void display(int n)
{
     struct node *temp;
     int i;
     printf("\n the adjecency list is:");
     for(i=0;i<n;i++)
     {
        printf("%d->",i+1);
        temp=list[i];
        while(temp)
        {
             printf("%d->",temp->vertex);
             temp=temp->edge;
        }
        printf("NULL");
        printf("\n");
     }
}
int main()
{
      int i,d;
      readgraph();
      for(i=1;i<=n;i++)
      {
         d=getoutdegree(i);
         printf("outdegree of vertex %d is %d",i,d); 
         printf("\n");
         printf("\n");
      }
      for(i=1;i<=n;i++)
      {
        d=getindegree(i);
        printf("indegree of vertex %d is %d",i,d); 
        printf("\n");
        printf("\n");
      }
      display(n);
      
}
