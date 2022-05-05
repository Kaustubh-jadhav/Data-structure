#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct bst
{
    int data;
    struct bst *left,*right;
}*root=NULL,*temp,*t,*t1;

struct queue
{
    struct bst *qdata[MAX];
    int f,r;
};

int num,x,cn=0,level=0,cnt=1,total=1;

void initq(struct queue *pq)
{
    pq->f=pq->r=-1;
}

void insertq(struct queue *pq,struct bst *t)
{
    pq->qdata[++pq->r]=t;
}

struct bst *deleteq(struct queue *pq)
{
    return pq->qdata[++pq->f];
}

int emptyq(struct queue *pq)
{
    return (pq->f==pq->r);
}

void insertbst(int num)
{
    temp=malloc(sizeof(struct bst*));
    temp->data=num;
    temp->left=temp->right=NULL;
    if(root==NULL)
        root=t=temp;
    else
    {
        for(t=root;t!=NULL;)
        {
            t1=t;
            if(temp->data<=t->data)
               t=t->left;
            else 
               t=t->right;
        }
        if(temp->data<=t1->data)
            t1->left=temp;
        else
            t1->right=temp;
    }
}
void inorderbst(struct bst *t)
{
    if(t!=NULL)
    {
        inorderbst(t->left);
        printf(" %d",t->data);
        inorderbst(t->right);
    }
}
void preorderbst(struct bst* t)
{
    if(t!=NULL)
    {
        printf(" %d",t->data);
        preorderbst(t->left);
        preorderbst(t->right);
    }
}
void postorderbst(struct bst* t)
{
    if(t!=NULL)
    {
        postorderbst(t->left);
        postorderbst(t->right);
        printf(" %d",t->data);
    }
}
void levelorder(struct bst *temp)
{
    temp=root;
    struct queue q;
    insertq(&q,temp);
    insertq(&q,NULL);
    printf("\n Level : %d Total node : %d Nodes : ",cnt,cnt,total);
    while(!emptyq(&q))
    {
        temp=deleteq(&q);
        if(temp!=NULL)
        {
            total++;
            cnt++;
            printf(" %d - ",temp->data);
            if(temp->left!=NULL)
                insertq(&q,temp->left);
            if (temp->right!=NULL)
                insertq(&q,temp->right);
        }
        else
        {
            if(!emptyq(&q))
            {
                printf("\n");
                printf("\n Level : %d Total node : %d Nodes : ",cnt,cnt,total);
                cnt=1;
                level++;
            }
            insertq(&q,NULL);
        }
        
    }
    printf("\n Total level : %d ",level+1);
}

int cntbst(struct bst *t)
{
    if(t!=NULL)
    {
        cntbst(t->left);
        cn++;
        cntbst(t->right);
    }
    return cn;
}

int main()
{
     printf("\n Enter a node to be inserted in Binary tree :");
     scanf("%d",&num);
     while(num!=0)
     {
         insertbst(num);
         printf("\n Enter a node to be inserted in Binary tree :");
         scanf("%d",&num);
     }
     printf("\nBinary search tree in inorder: start-->");
     inorderbst(root);
     printf("\nBinary search tree in preorder: start-->");
     preorderbst(root);
     printf("\nBinary search tree in postorder: start-->");
     postorderbst(root);
     printf("\n ---level order traversal---");
     levelorder(root);
     cntbst(root);
     printf("\n Total number of nodes in Tree is %d ",cn);
     return 0;
}