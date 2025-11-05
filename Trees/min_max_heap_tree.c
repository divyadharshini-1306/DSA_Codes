#include <stdio.h>
#include <stdlib.h>

// Max number of elements in the heap
#define MAX_SIZE 100

// --- MAX-HEAP Implementation ---

// Function to swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to restore the Max-Heap property starting from a given index 'i'
void maxHeapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to insert a new element into the Max-Heap
void insertMaxHeap(int arr[], int *n, int key) {
    if (*n >= MAX_SIZE) {
        printf("Error: Max Heap is full.\n");
        return;
    }

    // 1. Insert the new element at the end
    arr[*n] = key;
    int i = *n;
    (*n)++;

    // 2. Perform "Up-Heapify" (bubble up) to restore the Max-Heap property
    // While the element is not the root and is greater than its parent
    while (i != 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove and return the maximum element (root) from Max-Heap
int extractMax(int arr[], int *n) {
    if (*n <= 0)
        return -1; // Heap is empty

    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    // 1. Store the maximum element (root)
    int root = arr[0];

    // 2. Replace root with the last element
    arr[0] = arr[*n - 1];
    (*n)--;

    // 3. Perform "Down-Heapify" on the new root
    maxHeapify(arr, *n, 0);

    return root;
}

// --- MIN-HEAP Implementation ---

// Function to restore the Min-Heap property starting from a given index 'i'
void minHeapify(int arr[], int n, int i) {
    int smallest = i;         // Initialize smallest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than current smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

// Function to insert a new element into the Min-Heap
void insertMinHeap(int arr[], int *n, int key) {
    if (*n >= MAX_SIZE) {
        printf("Error: Min Heap is full.\n");
        return;
    }

    // 1. Insert the new element at the end
    arr[*n] = key;
    int i = *n;
    (*n)++;

    // 2. Perform "Up-Heapify" (bubble up) to restore the Min-Heap property
    // While the element is not the root and is smaller than its parent
    while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove and return the minimum element (root) from Min-Heap
int extractMin(int arr[], int *n) {
    if (*n <= 0)
        return -1; // Heap is empty         
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    // 1. Store the minimum element (root)
    int root = arr[0];

    // 2. Replace root with the last element
    arr[0] = arr[*n - 1];
    (*n)--;

    // 3. Perform "Down-Heapify" on the new root
    minHeapify(arr, *n, 0);

    return root;
}

// Utility function to print the heap array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- Driver Code ---

int main() {
    // --- Min-Heap Demonstration ---
    int minHeapArr[MAX_SIZE];
    int minHeapSize = 0;

    printf("--- Min-Heap Operations ---\n");
    insertMinHeap(minHeapArr, &minHeapSize, 10);
    insertMinHeap(minHeapArr, &minHeapSize, 5);
    insertMinHeap(minHeapArr, &minHeapSize, 20);
    insertMinHeap(minHeapArr, &minHeapSize, 3);
    insertMinHeap(minHeapArr, &minHeapSize, 15);

    printf("Min-Heap (Array View): ");
    printArray(minHeapArr, minHeapSize); // Expected: 3 5 15 10 20

    printf("Extract Min: %d\n", extractMin(minHeapArr, &minHeapSize)); // Should be 3
    printf("Min-Heap (After extraction): ");
    printArray(minHeapArr, minHeapSize); // Expected: 5 10 15 20 (Order may vary based on heapify path)

    // --- Max-Heap Demonstration ---
    int maxHeapArr[MAX_SIZE];
    int maxHeapSize = 0;

    printf("\n--- Max-Heap Operations ---\n");
    insertMaxHeap(maxHeapArr, &maxHeapSize, 10);
    insertMaxHeap(maxHeapArr, &maxHeapSize, 5);
    insertMaxHeap(maxHeapArr, &maxHeapSize, 20);
    insertMaxHeap(maxHeapArr, &maxHeapSize, 3);
    insertMaxHeap(maxHeapArr, &maxHeapSize, 15);

    printf("Max-Heap (Array View): ");
    printArray(maxHeapArr, maxHeapSize); // Expected: 20 15 10 3 5

    printf("Extract Max: %d\n", extractMax(maxHeapArr, &maxHeapSize)); // Should be 20
    printf("Max-Heap (After extraction): ");
    printArray(maxHeapArr, maxHeapSize); // Expected: 15 5 10 3 (Order may vary based on heapify path)

    return 0;
}