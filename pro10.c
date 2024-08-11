#include <stdio.h>  
void swap(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
int partition(int arr[], int low, int high)  
{  
    int pivot = arr[low]; 
    int i = low; 
    int j = high; 
    while (i < j)  
    {  
        while (arr[i] <= pivot && i <= high - 1)  
        {  
            i++; 
        } 
        while (arr[j] > pivot && j >= low + 1)  
        {  
            j--; 
        } 
        if (i < j)  
        {  
            swap(&arr[i], &arr[j]);  
        } 
    } 
    swap(&arr[low], &arr[j]);  
    return j;  
}  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
    int partitionIndex = partition(arr, low, high);  
    quickSort(arr, low, partitionIndex - 1);  
 
    quickSort(arr, partitionIndex + 1, high);  
    } 
} 
int main()  
{  
    int n,arr[10],i; 
    printf("enter the size of an array \n"); 
    scanf("%d",&n); 
printf("enter the lements are an array\n"); 
for(i=0;i<n;i++) 
scanf("%d",&arr[i]); 
printf("Original array: ");  
for (int i = 0; i < n; i++) 
{  
printf("%d ", arr[i]);  
}  
quickSort(arr, 0, n - 1);  
printf("\nSorted array: ");  
for (int i = 0; i < n; i++) 
{  
printf("%d ", arr[i]);  
}  
return 0;  
}