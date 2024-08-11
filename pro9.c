#include <stdio.h>
void selectsort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++) 
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
int main()
{
    int a[10], n, i;
    printf("Enter the array size: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array elements before sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    selectsort(a, n);
    printf("\nArray elements after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}