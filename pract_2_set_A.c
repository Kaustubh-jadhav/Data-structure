#include<stdio.h>
#include<stdlib.h>

struct bst
{
      int data;
      struct bst *l,*r;
}*root=NULL,*t=NULL,*t1;

struct queue
{
     int data;
     struct queue *next;
}*f,*r,*t2=NULL,*ele;

int n;
void initbst(void);
void insertbst(int);
void inorder(struct bst*);
void preorder(struct bst*);
void postorder(struct bst*);
void level(struct bst*);
void insertq(int);
int emptyq(void);
void deleteq(void);

int cnt=0,total=0,lev=0,num;
main()
{
    int n,num; 
    initbst();
    printf("\n Enter integer data to create bst <Enter 0 to exit> :");
    scanf("%d",&num);
    while(num!=0)
    {
         insertbst(num);
         printf("\n Enter integer data to create bst <Enter 0 to exit> :");
         scanf("%d",&num);
    }
    inorder(root);
    printf("\n count of total node:");
    level(root);
    printf("\n %d ",cnt);
    printf("\n level is %d ",total);
}
void initbst(void)
{
     root=NULL;
}
void initq(void)
{
     f=r=NULL;
}
void postorder(struct bst *t)
{
     if(t!=NULL)
     {
        postorder(t->l);
        postorder(t->r);
        printf("%d ",t->data);     
     }
}
void preorder(struct bst *t)
{
     if(t!=NULL)
     {
        printf("%d ",t->data);
        preorder(t->l);
        preorder(t->r);       
     }
}
void inorder(struct bst *t)
{
     if(t!=NULL)
     {
        inorder(t->l);
        printf("%d ",t->data);
        inorder(t->r);       
     }
}
void insertbst(int num)
{
         struct bst *temp;
         temp=malloc(sizeof(struct bst));
         temp->data=num;
         if (root==NULL)
            root=t=temp;
         else
         {
            for (t=root;t!=NULL;)
            {
                t1=t;
                if (temp->data<=t->data)
                    t=t->l;
                else
                    t=t->r;    
            }
            if(temp->data<=t1->data)
               t1->l=temp;
            else
               t1->r=temp;
         }
}
void insertq(int num)
{
     struct queue *temp;
     temp=malloc(sizeof(struct queue));
     temp->data=num;
     if(f==NULL && r==NULL)
     {
         r=f=temp;
     }
     else
     { 
         r->next=temp;
         r=r->next;
     }
     temp->next=f;
}
void level(struct bst *t)
{
     int temp;
     temp=t->data;
     insertq(temp);
     insertq(NULL);
     while(f!=NULL)
          deleteq();
     if(temp!=NULL)
     {
        total=total+1;
        cnt=cnt+1;
        printf("%d ",t->data);
        if(t->l!=NULL)
           insertq(t->l);
        else if(t->r!=NULL)
           insertq(t->r);
     }
     else
     {
         if(f!=NULL)
            printf("\n");
         printf("%d ",cnt);
         cnt=0;
         lev=lev+1;
     }
     insertq(0);
}
int emptyq(void)
{
     if(f==NULL)
        return 1;
     else
        return 0;
}
void deleteq(void)
{
     struct queue *temp;
     num=f->data;
     if (r==f)
        r=f=NULL;
     else
     {
        r->next=temp;
        r=r->next;
     }
     temp->next=f;
}
