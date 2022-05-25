#include<stdio.h>
#include<stdlib.h>

struct node
{
	float data;
	struct node *next;
}*first=NULL,*temp,*t;

int n;

void createsll(int);
void printsll(void);
void insertsll(int);
void deletepsll(int);
void deletevsll(float);
void searchsll(float);
void reverssll(void);

main()
{
    int op=1,pos,x;
    while (op>=1 && op<=7)
    {
     	printf("\n singly linked list \n");
        printf("\n 1) create singly linked list.");
	printf("\n 2) display singly linked list.");
        printf("\n 3) insert element in linked list");
        printf("\n 4) delete element from linked list");
        printf("\n 5) delete by value");
        printf("\n 6) find element in linked list");
        printf("\n 7) reverse the linked list");
        printf("\n 8) exit");

	printf("\n Enter an option to perform task :");
	scanf("%d",&op);
	
	switch(op)
	{
	      case 1:if(first!=NULL)
	             {
		     	printf("\n linked list already created !!");
		        break;
		     }
	             else
		     {
		        printf("\nEnter number of node to be create :");
	                scanf("%d",&n);
                        createsll(n);
		        break;
	             }
	      case 2:if(first==NULL)
		     {
                        printf("\n linked list is not created !!");
                        return;
		     }
                     else
                     {
                        printsll();
                        break;
                     }
              case 3:if(first==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                      else
                     {
			printf("\nEnter a position :");
                        scanf("%d",&pos);
                        insertsll(pos);
                        printf("\n After insertion linked list is :");
                        printsll();    
                        break;
                     }
              case 4:if(first==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                     else
                     {
                        printf("\n Enter position to delete :");
                        scanf("%d",&pos);
                        deletepsll(pos);
                        printf("\n after deletion linked list is :");
                        printsll();
                        break;
                     }
               case 5:if(first==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                     else
                     {
                        printf("\n Enter value to delete :");
                        scanf("%f",&x);
                        deletevsll(x);
                        printf("\n after deletion linked list is :");
                        printsll();
                        break;
                     }
                case 6:if(first==NULL)
                       {
                          printf("\n linked list is not created !!");
                          return;
                       }
                       else
                       {
                          printf("\n Enter element to find .");
                          scanf("%f",&x);
                          searchsll(x);
                          break;
                       }
                case 7:if(first==NULL)	
                       {
                          printf("\n linked list is not created !!");
                          return;
                       }
                       else
                       {
                          reverssll();
                          break;
                       }
                case 8:return;
                         
                         
             
	}	
    }
}
void createsll(n)
{
      int i;
      for(i=1;i<=n;i++)
      {
          temp=malloc(sizeof(struct node));
          printf("Enter data %d :",i);
          scanf("%f",&temp->data);
         
          if(i==1)
             first=t=temp;
          else
          {
             t->next=temp;
             t=temp;
          }
      }
      printsll();
}
void printsll()
{
      printf("\n Linked list :");
      for(t=first;t->next!=NULL;t=t->next)
      {
          printf("%f->",t->data);
      }
      printf("%f->NULL",t->data);
}
void insertsll(int pos)
{
     int i;
     temp=malloc(sizeof(struct node));
     printf("\n Enter data for insert at %d :",pos);
     scanf("%f",&temp->data);
     if (pos==1)
     {
        temp->next=first;
        first=temp;
     }
     else
     {
        for(i=1,t=first;i<pos-1&&t->next!=NULL;t=t->next,i++);
        {
           temp->next=t->next;
           t->next=temp;
        }
     }
     n++;
     printf("\nAfter insertion total number of node is :%d",n);
}
void deletepsll(int pos)
{
     int i;
     if(pos==1)
     {
        temp=first;
        first=first->next;
     }
     else
     {
        for(i=1,t=first;i<pos-1&&t->next!=NULL;t=t->next,i++);
        {
           temp=t->next;
           if (t->next!=NULL)
           {
              t->next=temp->next;
           }
        }
     }
 n--;
}
void deletevsll(float x)
{
     for (t=first;t->next!=NULL;t=t->next)
     {
         if (t->data==x)
            break; 
         temp=t;
     }
     if (t==NULL)
        printf("\n Error..data not found");
     
     else
        if (t==first)
           first=first->next;
        else
           temp->next=t->next;
     n--;
}
void searchsll(float x)
{
     int i=1;
     for (t=first;t->next=NULL;t=t->next)
     {   
         if (t->data==x)
            printf("\n Elememt found at postion %d :",i);
      i++;
     }
}
void reverssll(void)
{
     struct node *t1,*t2;
     for (t=first,t1=t->next,t2=t1->next,t1->next!=NULL;t2=t2->next;)
     {
          t1->next=t;
          t=t1;
          t1=t2;
     }
     t1->next=t;
     first->next=NULL;
     first=t1;
     printf("\n string is reversed");
     printsll();
}

























