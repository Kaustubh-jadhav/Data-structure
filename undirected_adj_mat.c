#include<stdio.h>
#define N 10
int n=0 ,a[N][N];
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
              a[stop][start]=1;
       }

}

void showgraph()
{
    int i,j;
    printf("\n adjecency matris is :\n");
    printf(" ");
    for(i=1;i<=n;i++)
        printf("%4d",i);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d",i);
        for(j=1;j<=n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
}
int getdegree(int k)
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
    showgraph();
     for(i=1;i<=n;i++)
    {
        d=getdegree(i);
        printf("\ndegree of vertex %d is %d",i,d); 
        printf("\n");
        printf("\n");
    }
    
    
}
/*[sy12@pc62 Sem 4]$ cc undirected_adj_mat.c
[sy12@pc62 Sem 4]$ ./a.out

 Enter Number of vertices :4

 Enter vertex =1
 connected to =2

 Enter vertex =1
 connected to =3

 Enter vertex =2
 connected to =3

 Enter vertex =2
 connected to =4

 Enter vertex =3
 connected to =4

 Enter vertex =0
 connected to =0

 adjecency matris is :
    1   2   3   4
1   0   1   1   0
2   1   0   1   1
3   1   1   0   1
4   0   1   1   0

degree of vertex 1 is 2


degree of vertex 2 is 3


degree of vertex 3 is 3


degree of vertex 4 is 2

[sy12@pc62 Sem 4]$ 
*/

