#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *next,*prev;
}*startl=NULL,*startr=NULL,*temp,*t;

int n;

void createdll(int);
void printdll(void);
void insertdll(int);
void deletepdll(int);
void deletevdll(void);
void searchdll(void);
void reversdll(void);

main()
{
    int op=1,pos;
    float x;
    while (op>=1 && op<=7)
    {
     	printf("\n doubly linked list \n");
        printf("\n 1) create doubly linked list.");
	printf("\n 2) display doubly linked list.");
        printf("\n 3) insert element in linked list");
        printf("\n 4) delete by postion");
        printf("\n 5) delete by value");
        printf("\n 6) search in linked list");
        printf("\n 7) reverse the string");
        printf("\n 8) exit");

	printf("\n Enter an option to perform task :");
	scanf("%d",&op);
	
	switch(op)
	{
	      case 1:if(startl!=NULL)
	             {
		     	printf("\n linked list already created !!");
		        break;
		     }
	             else
		     {
		        printf("\nEnter number of node to be create :");
	                scanf("%d",&n);
                        createdll(n);
		        break;
	             }
	      case 2:if(startl==NULL)
		     {
                        printf("\n linked list is not created !!");
                        return;
		     }
                     else
                     {
                        printdll();
                        break;
                     }
              case 3:if(startl==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                      else
                     {
			printf("\n Enter position between 0 to %d delete :",n+1);
                        scanf("%d",&pos);
                        insertdll(pos);
                        printf("\n After insertion linked list is :");
                        printdll();    
                        break;
                     }
              case 4:if(startl==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                     else
                     {
                        printf("\n Enter position between 0 to %d delete :",n);
                        scanf("%d",&pos);
                        deletepdll(pos);
                        printf("\n after deletion linked list is :");
                        printdll();
                        break;
                     }
              case 5:if(startl==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                     else
                     {
                        deletevdll();
                        printf("\n after deletion linked list is :");
                        printdll();
                        break;
                     } 
               case 6:if(startl==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                     else
                     {
                        searchdll();
                        break;
                     }
              case 7:if(startl==NULL)
                     {
                        printf("\n linked list is not created !!");
                        return;
                     }
                     else
                     {
                        reversdll();
                        printdll();
                        break;
                     }
              case 8:return;    
             
	}	
    }
}
void createdll(int n)
{
      int i;
      for(i=1;i<=n;i++)
      {
          temp=malloc(sizeof(struct node));
          printf("Enter data %d :",i);
          scanf(" %c",&temp->data);
         
          if(i==1)
             startl=t=temp;
          else
          {
             t->next=temp;
             temp->prev=t;
             t=temp;
          }
      startl->prev=NULL;
      startr=temp;
      startr->next=NULL;
      }
      printdll();
}
void printdll()
{
      printf("\n Linked list from left to right :: startl->\n");
 
      for(t=startl;t->next!=NULL;t=t->next)
      {
          printf(" %c->",t->data);
      }
      printf(" %c->NULL",t->data);
 
      printf("\n\nLinked list from  right to left :: startr->\n");
      for(t=startr;t->prev!=NULL;t=t->prev)
      {
          printf(" %c->",t->data);
      }
      printf(" %c->NULL",t->data);
}
void insertdll(int pos)
{
     int i;
     temp=malloc(sizeof(struct node));
     printf("\n Enter data for insert at %d :",pos);
     scanf(" %c",&temp->data);
     if (pos==1)
     {
        temp->next=startl;
        startl->prev=temp;
        startl=temp;
     }
     else
     {
        for (i=1,t=startl;i<pos-1 && t->next!=NULL;t=t->next,i++);
        temp->next=t->next;
        if (t!=startr)
           t->next->prev=temp;
        else
           startr=temp;
        t->next=temp;
        temp->prev=t;
     }
     n++;
     printf("\nAfter insertion total number of node is :%d",n);
}
void deletepdll(int pos)
{
     int i;
     if (pos==1)
     {
	if (startl=startr)
            startl=startr=NULL;
        else
        {
            startl=startl->next;
            startl->prev=NULL;
        }
     }
     else
     {
        for(i=1,t=startl;i<pos-1 && t->next!=NULL;t=t->next,i++);
        temp=t->next;
        t->next=temp->next;
        if (temp!=startr)
            temp->next->prev=t;
        else
        {
            t->next=NULL;
            startr=t;
        }        
      }
      n--;
      printf("\n After deletion number of node in doubly linked list is %d",n);
}

void deletevdll(void)
{
     char x;
     printf("\n Enter value to delete :");
     scanf(" %c",&x);
     int i;
     for(t=startl,i=1;t->next!=NULL;i++,t=t->next)
     {
         if(t->data==x)
           break;
         temp=t;
     }
     if(t==NULL)
     {
        printf("\n Error.. element not found");
     }
     else
     {     
        if(startl==startr)
           startl=startr=NULL;
        else
           if (t==startl)
           {
              startl=startl->next;
              startl->prev=NULL;
           }
           else
           {
              if (t==startr)
              {
                  startr=startr->prev;
                  startr->next=NULL;
              }
              else
              {
                  t->prev->next=t->next;
                  t->next->prev=t->prev;
              }
           }
              
     }
 n--;
}
void searchdll(void)
{
     char x;
     printf("\n Enter element to search :");
     scanf(" %c",&x);
     int i;
     for(t=startl,i=1;t->next!=NULL;i++,t=t->next)
     {
         if(t->data==x)
         {
            printf("\n Element found at postion %d",i);
            break;
         }
     }
     if(t==NULL)
     {
        printf("\n Error.. element not found");
     }
}
void reversdll(void)
{
     struct node *t1,*t2,*tt;
     tt=startl;
     for (t=startl,t1=t->next,t2=t1->next;t1->next!=NULL;t2=t2->next)
     {
         t1->next=t;
         t->prev=t1;
         t=t1;
         t1=t2;
     }
     t1->next=t;
     t->prev=t1;
     t1->prev=NULL;
     startl->next=NULL;
     startr=startl;
     startl=t1;
     tt->next=NULL;
      printf("\n linked list is reversed");
}
/*[sy12@pc53 Sem 4]$ cc doubly_ch.c
[sy12@pc53 Sem 4]$ ./a.out

 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :1

Enter number of node to be create :5
Enter data 1 :k
Enter data 2 :a
Enter data 3 :u
Enter data 4 :s
Enter data 5 :t

 Linked list from left to right :: startl->
 k-> a-> u-> s-> t->NULL

Linked list from  right to left :: startr->
 t-> s-> u-> a-> k->NULL
 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :5

 Enter value to delete :s

 after deletion linked list is :
 Linked list from left to right :: startl->
 k-> a-> u-> t->NULL

Linked list from  right to left :: startr->
 t-> u-> a-> k->NULL
 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :3

 Enter position between 0 to 5 delete :4

 Enter data for insert at 4 :s

After insertion total number of node is :5
 After insertion linked list is :
 Linked list from left to right :: startl->
 k-> a-> u-> s-> t->NULL

Linked list from  right to left :: startr->
 t-> s-> u-> a-> k->NULL
 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :6

 Enter element to search :a

 Element found at postion 2
 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :4

 Enter position between 0 to 5 delete :3

 After deletion number of node in doubly linked list is 4
 after deletion linked list is :
 Linked list from left to right :: startl->
 k-> a-> s-> t->NULL

Linked list from  right to left :: startr->
 t-> s-> a-> k->NULL
 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :7

 linked list is reversed
 Linked list from left to right :: startl->
 t-> s-> a-> k->NULL

Linked list from  right to left :: startr->
 k-> a-> s-> t->NULL
 doubly linked list 

 1) create doubly linked list.
 2) display doubly linked list.
 3) insert element in linked list
 4) delete by postion
 5) delete by value
 6) search in linked list
 7) reverse the string
 8) exit
 Enter an option to perform task :8
[sy12@pc53 Sem 4]$ ^C
[sy12@pc53 Sem 4]$ 
*/

















