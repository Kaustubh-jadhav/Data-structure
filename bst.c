#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *l, *r;
} *root = NULL, *t, *temp, *t1;

void initbst(void);
void createbst(int);
void search(int);
void inorder(struct bst *);
void preorder(struct bst *);
void postorder(struct bst *);
void displaybst(void);

int searchbst(int);

int n;
main()
{
    int op = 1, pos, x;
    initbst();
    while (op >= 1 && op <= 3)
    {
        printf("\n Binary search tree \n");
        printf("\n 1)create bst ");
        printf("\n 2)traverse in bst ");
        printf("\n 3)search in bst \n");
        printf("\n Enter an option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            if (root != NULL)
                printf("\n Binary search tree is already created.");
            else
            {
                printf("\n Enter number of node:");
                scanf("%d", &n);
                if (n <= 0)
                    printf("\n Invalid number of node.");
                else
                {
                    root = NULL;
                    createbst(n);
                }
            }
            break;
        case 2:
            if (root == NULL)
                printf("\n Binary tree is not created.");
            else
            {
                printf("\n Binary search tree inorder :\n start ->");
                inorder(root);
                printf("\n Binary search tree Preorder : \n start ->");
                preorder(root);
                printf("\n Binary search tree postorder :\n start ->");
                postorder(root);
            }
            break;
        case 3:
            if (root == NULL)
                printf("\n Binary tree is not created.");
            else
            {
                printf("\n Enter element to search in bst :");
                scanf("%d", &x);
                search(x);
            }
            break;
        }
    }
}
void initbst(void)
{
    root = NULL;
}
void createbst(n)
{
    int num, i;

    for (i = 1; i <= n; i++)
    {
        printf("\n Enter data for %d :", i);
        scanf("%d", &num);

        temp = malloc(sizeof(struct bst));
        temp->data = num;
        temp->l = temp->r = NULL;
        if (i == 1)
            root = t = temp;
        else
        {
            for (t = root; t != NULL;)
            {
                t1 = t;
                if (temp->data <= t->data)
                    t = t->l;
                else
                    t = t->r;
            }
            if (temp->data <= t1->data)
                t1->l = temp;
            else
                t1->r = temp;
        }
    }
}
void inorder(struct bst *t)
{
    if (t != NULL)
    {
        inorder(t->l);
        printf(" %d", t->data);
        inorder(t->r);
    }
}
void preorder(struct bst *t)
{
    if (t != NULL)
    {
        printf(" %d", t->data);
        preorder(t->l);
        preorder(t->r);
    }
}
void postorder(struct bst *t)
{
    if (t != NULL)
    {
        postorder(t->l);
        postorder(t->r);
        printf(" %d", t->data);
    }
}
void search(int x)
{
    
    if (x == t->data)
    {
        printf("\n %d element found ",t->data);
        return;
    }
    else if (x < t->data)
       return search(t->l);
    else 
       return search(t->r);
}