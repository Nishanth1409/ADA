#include <stdio.h>
int a[10];
void merge(int a[], int low, int mid, int high) 
{
    int i, j, k;
    int temp[10]; 
    i = low; 
    j = mid + 1; 
    k = low;
    while (i <= mid && j <= high) 
    {
       if (a[i] <= a[j]) 
       {
           temp[k++] = a[i++];
       } 
       else 
       {
           temp[k++] = a[j++];
       }
    }
    while (i <= mid) 
    {
       temp[k++] = a[i++];
}
    while (j <= high) 
    { 
       temp[k++] = a[j++];
    }
    for (i = low; i <= high; i++) 
    {
       a[i] = temp[i];
    }
}
void mergesort(int a[], int low, int high) 
{
   if (low < high) 
   {
       int mid = low + (high - low) / 2;
       mergesort(a, low, mid);
       mergesort(a, mid + 1, high);
       merge(a, low, mid, high);
   }
}
int main() 
{
    int i, n;
    printf("Enter size of array (max 10): ");
    scanf("%d", &n);
    if (n > 10) 
    {
        printf("Size exceeds maximum array limit of 10.\n");
        return 1;
    }
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    printf("Array elements before sorting:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("\nArray elements after sorting:\n");
    for (i = 0; i < n; i++) 
    {
      printf("%d\t", a[i]);
    }
    return 0;
}