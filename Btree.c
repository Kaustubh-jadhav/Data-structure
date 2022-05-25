#include<stdio.h>
#include<stdlib.h>

struct bst
{
      int data;
      struct bst *l,*r;
}*root=NULL,*temp=NULL,*t=NULL,*t1;

int n,flag;
void display(void);
void initbst(void);
void createbst(int);
void searchbst(struct bst*,int);
void searchbstd(struct bst *t,int i);
void insertbst(int,int);
void inorder(struct bst*);
void preorder(struct bst*);
void postorder(struct bst*);
struct bst *inorder_succesor(struct bst*);
struct bst *deletebst(struct bst*,int);


//void displaybst(void);

main()
{
    int n,op=1,num,f; 
    initbst();
    while(op>=1 && op<=5)
    {
         printf("\n\n Binary search tree ");
         printf("\n 1)create binary tree ");
         printf("\n 2)display in binary tree");
         printf("\n 3)search in binary tree");
         printf("\n 4)insert in binary tree");
         printf("\n 5)delete in binary tree");
         printf("\n 6)Exit");
         printf("\n Enter prefered choice:");
         scanf("%d",&op);
         switch(op)
         {
               case 1:if(root!=NULL)
                         printf("\n Binary tree is already created");
                      else
                      {
                         printf("\n Enter number of nodes :");
                         scanf("%d",&n);
                         if(n<=0)
                            printf("\n Invalid number of node !");
                         else
                         { 
                            root=NULL;
                            createbst(n);
                         }
                     }
                     break;
                                                  
               case 2:if(root==NULL)
                         printf("\n BInary tree is not created");
                      else
                      { 
                         display();
                      }	 
                      break;
               case 3:printf("\n Enter data to search :");
                      scanf("%d",&num);
                      searchbst(root,num);
                      break;
               case 4:printf("\n Enter data to insert :");
                      scanf("%d",&num);
                      insertbst(num,n);
                      printf("%d is inserted",num);
                      display();
                      break;
               case 5:if(root==NULL)
                        printf("\n bst is empty ");
                      else
                      {
                        printf("\n Enter node to delete:");
                        scanf("%d",&num);
                        deletebst(root,num);
                        if(flag==1)
                        {
                           printf("\n %d element deleted",num);
                           flag=0;
                           display();
                        }
                        else
                           printf("\n element not found");
                        break;
                        
                      }
              
              
         }
     }	
}

void initbst(void)
{
     root=NULL;
}
void createbst(n)
{
     int num,i;
     for (i=1;i<=n;i++)
     {
         printf("\n Enter data for %d :",i);
         scanf("%d",&num);
         insertbst(num,i);
     }
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
void display()
{
      printf("\n Binary tree is inorder \n start->");
      inorder(root);
      printf("\n Binary tree is preorder \n start->");
      preorder(root);
      printf("\n Binary tree is postorder \n start->");
      postorder(root);
      return;
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
void searchbst(struct bst *t,int i)
{
     int flag;
     if(t==NULL)
     {
        printf("\n %d not found",i);
        return;
     }
     else if(t->data==i)
     {
        printf("\n %d found",i);
        return;
     }
     else if(i<t->data)
        searchbst(t->l,i);
     else
        searchbst(t->r,i);
}
void insertbst(int num,int i)
{
         temp=malloc(sizeof(struct bst));
         temp->data=num;
         if (i==1)
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
struct bst*inorder_successor(struct bst *t)
{
      t1=t;
      while(t1->l!=NULL)
           t1=t1->l;
      return t1;
}
void searchbstd(struct bst *t,int i)
{
     if(t==NULL)
     {
        return;
     }
     else if(t->data==i)
     {
        flag=1;
        return;
     }
     else if(i<t->data)
        searchbstd(t->l,i);
     else
        searchbstd(t->r,i);
}
struct bst *deletebst(struct bst *t,int num)
{
      searchbstd(t,num);
      if(t==NULL)
         return t;
      else if(num<t->data)
         t->l=deletebst(t->l,num);
      else if(num>t->data)
         t->r=deletebst(t->r,num);
      else
      {
         if(t->l==NULL)
         {
             temp=t->r;
             return temp;
         }
         else
         {
             temp=t->l;
             return temp;
         }
         temp=inorder_successor(t->r);
         t->data=temp->data;
         t->r=deletebst(t->r,temp->data);
      }
      return t;
}

