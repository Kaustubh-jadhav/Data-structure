//pract 1 set B

#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *l,*r;
}*root=NULL,*temp,*t,*t1;
int num,cnt;
void initbst(void)
{
    root=NULL;
}
void insertbst(int num)
{
    temp=malloc(sizeof(struct bst*));
    temp->data=num;
    temp->l=temp->r=NULL;
    if(root==NULL)
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
            leafbst(t->l);
            leafbst(t->r);
        }
    }
    return cnt;
}
int main()
{
     printf("\n Enter a node to be inserted in Binary search tree :");
     scanf("%d",&num);
     while(num!=0)
     {
         insertbst(num);
         printf("\n Enter a node to be inserted in Binary search tree :");
         scanf("%d",&num);
     }
     printf("\nBinary search tree in inorder: start-->");
     inorderbst(root);
     printf("\nBinary search tree in preorder: start-->");
     preorderbst(root);
     printf("\nBinary search tree in postorder: start-->");
     postorderbst(root);
     cntbst(root);
     printf("\n total no of nodes in bst is %d:\n",cnt);
     cnt=0;
     leafbst(root);
     printf("\n total no of leaf nodes in bst is %d:\n",cnt);
}