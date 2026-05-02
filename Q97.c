#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start, end;
} Interval;

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Min-heap functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Insert into heap
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Remove min (top)
int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// Get minimum element
int top(int heap[]) {
    return heap[0];
}

// Function to find minimum rooms
int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), compare);

    // Min heap to store end times
    int heap[n];
    int size = 0;

    // Add first meeting
    push(heap, &size, intervals[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        // If current meeting starts after earliest end
        if (intervals[i].start >= top(heap)) {
            pop(heap, &size); // reuse room
        }

        // Allocate room (push end time)
        push(heap, &size, intervals[i].end);
    }

    return size; // number of rooms needed
}

// Driver code
int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Interval intervals[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    int result = minMeetingRooms(intervals, n);

    printf("Minimum rooms required: %d\n", result);

    return 0;
}