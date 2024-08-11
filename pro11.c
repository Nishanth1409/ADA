#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int temp[10], i = low, j = mid + 1, k = 0;
    
    while (i <= mid && j <= high)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    
    for (i = low, k = 0; i <= high; i++, k++) arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[10], n;
    printf("Enter size of array (max 10): ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
