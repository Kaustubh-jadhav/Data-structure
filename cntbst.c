#include<stdio.h>
#include<stdlib.h>

struct bst
{
      int data;
      struct bst *l,*r;
}*root=NULL,*temp=NULL,*t=NULL,*t1;

int n;
void initbst(void);
void createbst(int);
void insertbst(int);
void inorder(struct bst*);
void preorder(struct bst*);
void postorder(struct bst*);
int cntbst(struct bst*);
int leafbst(struct bst*);

int cnt=0;
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
    printf("\n inorder of tree :");
    inorder(root);
    printf("\n preorder of tree :");
    preorder(root);
    printf("\n postorder of tree :");
    postorder(root);
    printf("\n");
    printf("\n count of total node:");
    cnt=cntbst(root);
    printf("%d",cnt);
    printf("\n count of leaf:");
    cnt=0;
    cnt=leafbst(root);
    printf("%d",cnt);
    printf("\n");
    printf("\n");
    
}

void initbst(void)
{
     root=NULL;
}
/*void createbst(n)
{
     int num,i;
     for (i=1;i<=n;i++)
     {
         printf("\n Enter data for %d :",i);
         scanf("%d",&num);
         insertbst(num,i);
     }
}*/
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
int cntbst(struct bst *t)
{
     if(t!=NULL)
     {
        cntbst(t->l);
        cnt++;
        cntbst(t->r);
     }
     return cnt;
}
int leafbst(struct bst *t)
{
     if(t!=NULL)
     {
        if(t->l==NULL && t->r==NULL)
           cnt++;
        else
        {
           leafbst(t->r);
           leafbst(t->l);
        }
     }
     return cnt;
}



