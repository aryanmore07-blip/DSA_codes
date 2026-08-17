#include <stdio.h>
#include <stdlib.h>


void acceptArray(int arr[], int *n);
void displayArray(int arr[], int n);
void shellSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void linearSearch(int arr[], int n);
void binarySearch(int arr[], int n);

int main() {
    int arr[10];
    int n = 0;
    int choice;

    do {
        printf("\n=================================");
        printf("\n         MAIN MENU               ");
        printf("\n=================================");
        printf("\n 1. Input Array");
        printf("\n 2. Display Array");
        printf("\n 3. Shell Sort");
        printf("\n 4. Selection Sort");
        printf("\n 5. Insertion Sort");
        printf("\n 6. Linear Search");
        printf("\n 7. Binary Search");
        printf("\n 8. Exit");
        printf("\n=================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                acceptArray(arr, &n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                shellSort(arr, n);
                break;
            case 4:
                selectionSort(arr, n);
                break;
            case 5:
                insertionSort(arr, n);
                break;
            case 6:
                linearSearch(arr, n);
                break;
            case 7:
                binarySearch(arr, n);
                break;
            case 8:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}


void acceptArray(int arr[], int *n) {
    printf("\nEnter number of elements (Max %d): ", 10);
    scanf("%d", n);
    if (*n <= 0 || *n > 10) {
        printf("Invalid size! Setting size to 0.\n");
        *n = 0;
        return;
    }
    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("\nArray is empty.\n");
        return;
    }
    printf("\nArray elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void shellSort(int arr[], int n) {
    if (n == 0) { printf("\nInput array first.\n"); return; }
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("\nArray sorted using Shell Sort.\n");
    displayArray(arr, n);
}

void selectionSort(int arr[], int n) {
    if (n == 0) { printf("\nInput array first.\n"); return; }
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    printf("\nArray sorted using Selection Sort.\n");
    displayArray(arr, n);
}

void insertionSort(int arr[], int n) {
    if (n == 0) { printf("\nInput array first.\n"); return; }
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\nArray sorted using Insertion Sort.\n");
    displayArray(arr, n);
}


void linearSearch(int arr[], int n) {
    if (n == 0) { printf("\nInput array first.\n"); return; }
    int key, found = 0;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("\nElement %d found at index %d (Position: %d).\n", key, i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nElement %d not found in the array.\n", key);
    }
}


void binarySearch(int arr[], int n) {
    if (n == 0) { printf("\nInput array first.\n"); return; }
    int key, found = 0;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            printf("\nElement %d found at index %d (Position: %d).\n", key, mid, mid + 1);
            found = 1;
            break;
        }
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found) {
        printf("\nElement %d not found (Note: Binary Search requires the array to be sorted).\n", key);
    }
}


