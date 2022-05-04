//pract 1 set A

#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *l,*r;
}*root=NULL,*temp,*t,*t1;

int n;
void initbst(void);
void createbst(int);
void inorderbst(struct bst* );
void preorderbst(struct bst* );
void postorderbst(struct bst* );
void insertbst(int,int);
void search(struct bst*,int);
int main()
{
    int op=1,num,node;
    while(op>=1 && op<=4)
    {
        printf("\n\nOperation on binary search tree ");
        printf("\n1.Create binary search tree ");
        printf("\n2.Tavarse binary search tree ");
        printf("\n3.insert node in binary search tree ");
        printf("\n4.search a node in binary search tree");
        printf("\nEnter a desired operation :");
        scanf("%d",&op);

        switch(op)
        {
            case 1 :if (root!=NULL)
                        printf("\n The binary search tree is already created..\n");
                    else
                    {
                        printf("\n Enter number of nodes in binary search tree : ");
                        scanf("%d",&n);
                        if (n<=0)
                            printf("\n Error!!Invalid number of nodes..\n");
                        else
                        {
                            root=NULL;
                            createbst(n);
                        }
                    }
                    break;

                case 2 : if (root==NULL)
                             printf("\n Binary search tree is Empty...\n");
                         else
                         {
                             printf("\nBinary search tree in inorder: start-->");
                             inorderbst(root);
                             printf("\nBinary search tree in preorder: start-->");
                             preorderbst(root);
                             printf("\nBinary search tree in postorder: start-->");
                             postorderbst(root);
                         }
                         break;

                case 3 : printf("\n Enter a node to be inserted in Binary search tree :");
                         scanf("%d",&num);
                         insertbst(num,++n);
                         break;
                case 4:printf("\n enter node to be searched");
                       scanf("%d",&node);
                       search(root,node);
                       break;
        }
    }
}
void initbst(void)
{
    root=NULL;
}
void createbst(int n)
{
    int num,i;
    for(i=1;i<=n;i++)
    {
        printf("\n Enter data for %d :",i);
        scanf("%d",&num);
        insertbst(num,i);

    }
}
void inorderbst(struct bst* t)
{
    if(t!=NULL)
    {
        inorderbst(t->l);
        printf(" %d",t->data);
        inorderbst(t->r);
    }
}
void preorderbst(struct bst* t)
{
    if(t!=NULL)
    {
        printf(" %d",t->data);
        preorderbst(t->l);
        preorderbst(t->r);
    }
}
void postorderbst(struct bst* t)
{
    if(t!=NULL)
    {
        postorderbst(t->l);
        postorderbst(t->r);
        printf(" %d",t->data);
    }
}
void insertbst(int num,int i)
{
    temp=malloc(sizeof(struct bst*));
    temp->data=num;
    temp->l=temp->r=NULL;
    if(i==1)
        root=t=temp;
    else
    {
        for(t=root;t!=NULL;)
        {
            t1=t;
            if(temp->data<=t->data)
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
void search(struct bst*t,int i)
{
    if (t==NULL)
        printf("\n data not found");
    else if(t->data==i)
        printf("\n data found");
    else if(i>t->data)
        search(t->r,i);
    else
        search(t->l,i);
}