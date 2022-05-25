#include<stdio.h>
#include<stdlib.h>
void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
       printf(" %d ",arr[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
  
    if(left<n && arr[left]>arr[largest])
       largest=left;
    if(right<n && arr[right]>arr[largest])
       largest=right;
    if(largest!=i)
    {
       swap(&arr[i],&arr[largest]);
       heapify(arr,n,largest);
    }

}
void heapsort(int arr[],int n)
{
    int i,temp;
    for(i = n/2-1; i>=0 ;i--)
        heapify(arr,n,i);
    printf("max heap :");
    printArray(arr,n);
    for(i =n-1 ;i>=0;i--)
    {
        printf("\nswap between %d to %d :",arr[0],arr[i]);
        swap(&arr[0],&arr[i]);
        printArray(arr,n);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[7],i=0,n;
    /*printf("\n Enter element in heap sort (0 to exit):");
    scanf("%d",&el);
    arr[i]=el;
    while(el!=0)
    {
         printf("Enter element in heap sort (0 to exit):");
         scanf("%d",&el);
         i++;
         arr[i]=el;
    }*/
    printf("Enter total number of node :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %d node :",i+1);
        scanf("%d",&arr[i]);
    }   
    //n= sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);   
    printf("\nSorted array is :");
    printArray(arr,n);
}
