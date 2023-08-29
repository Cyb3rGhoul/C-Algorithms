#include <stdio.h>

void swap(int* a, int* b){
    int swap = *a;
    *a = *b;
    *b = swap;
}

void bubble(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int j = i + 1;
        for (; j <= n; j++)
        {
            if (arr[i]>arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
        
    }

    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}


// Partition function to place the pivot element at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Merge sort function

// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i <= n; i++) {
        int min = i;
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] < arr[min]) {
                min = j; 
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
}
}

void print(int arr[], int n){
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}


int main(){
    int arr[100];
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter the array: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Sorted array using Bubble sort: ");
    bubble(arr, n);
    printf("\n");

    printf("Sorted array using Quick sort: ");
    quickSort(arr, 0, n);
    print(arr, n);
    printf("\n");

    printf("Sorted array using Merge sort: ");
    mergeSort(arr, 0, n - 1);
    print(arr, n);
    printf("\n");

    printf("Sorted array using Insertion sort: ");
    insertionSort(arr, n);
    print(arr, n);
    printf("\n");

    printf("Sorted array using Selection sort: ");
    selectionSort(arr, n);
    print(arr, n);

    return 0;
}