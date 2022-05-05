// Heap Sort 
  
  #include <stdio.h>
  #include<stdlib.h>
    
  void printArray(int arr[], int n)
  {
    for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
  void swap(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i)
  {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    
    if (largest != i)
    {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  
  void heapSort(int arr[], int n) 
  {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  printf("\n\nmax heap ->");
  printArray(arr,n);
  for (int i = n - 1; i >= 0; i--)
   {
        swap(&arr[0], &arr[i]);
        printf("\n after swapping %d and %d ->",arr[0],arr[i]);
        printArray(arr,n);
        heapify(arr, i, 0);
   }
  }
  

  
  
  int main()
  {
    int size,i,arr[7];
    printf("\n Enter size of binary tree :");
    scanf("%d",&size);
    for (i=0;i<size;i++)
    {
        printf("\n%d) Element -",i+1);
        scanf("%d",&arr[i]);
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, n);
  
    printf("\nSorted array is ->");
    printArray(arr, n);
  }
  /*
  Enter size of binary tree :7
1) Element -1
2) Element -12
3) Element -9
4) Element -5
5) Element -6
6) Element -7
7) Element -10
max heap ->12 6 10 5 1 7 9 

 after swapping 9 and 12 ->9 6 10 5 1 7 12 

 after swapping 7 and 10 ->7 6 9 5 1 10 12 

 after swapping 1 and 9 ->1 6 7 5 9 10 12 

 after swapping 5 and 7 ->5 6 1 7 9 10 12 

 after swapping 1 and 6 ->1 5 6 7 9 10 12 

 after swapping 1 and 5 ->1 5 6 7 9 10 12 

 after swapping 1 and 1 ->1 5 6 7 9 10 12 

Sorted array is ->1 5 6 7 9 10 12 
*/