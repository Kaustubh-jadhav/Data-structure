#include<stdio.h>
#define N 10
int n=0 ,a[N][N];
/*void vertex(int z)
{   
     int i,j;
     while(z!=0)
     {
          for(i=0;i<n;i++)
          {
              if(z==i)
              {
                  a[i][j]=1;
              }
              else
                  a[i][j]=0;
          }
     }
}*/
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
                     
          /*while(z!=0)
          {
              for(j=1;j<=n;j++)
              { 
                  if(j==z)
                     a[i][j]=1;
                  else
                     a[i][j]=0;
              }
          }*/

              
       }
        /*for(j=0;j<n;j++)
        {
            printf("\n Enter connected vertex :",j+1);
            scanf("%d",&a[i][j]);
        }*/

}

void showgraph()
{
    int i,j;
    printf("\n adjecency matris is :\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
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
main()
{
    int ch=0,k,d,i;
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
    
    showgraph();
    
    /*while(ch!=6)
    {
         printf("\n 1.read graph");
         printf("\n 2.show graph");
         printf("\n 3.degree of vertex");
         printf("\n 4,show degree of all vertex");
         printf("\n 5.show indegree and outdegree");
         printf("\n 6.exit");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                  readgraph();
                  break;
             case 2:
                  showgraph();
                  break;
             case 3:
                  printf("\n Enter vertex number:");
                  scanf("%d",&k);
                  d=getdegree(k);
                  if(k==-1)
                     printf("\n invalid vertex");
                  else
                     printf("\n degree of vertex %d is %d",k,d);
                  break;
            case 4:
                 printf("\n Enter vertex to find indegree:");
                 scand("%d",&k);
                 d=                        
    }
    */
}
