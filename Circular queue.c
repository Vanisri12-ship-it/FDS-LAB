#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Maximum capacity of the queue

int items[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull() {
    if ((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Add an element to the queue (Enqueue)
void enqueue(int element) {
    if (isFull()) {
        printf("\nQueue is full! Cannot insert %d.\n", element);
    } else {
        if (front == -1) {
            front = 0; // If inserting the first element
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted -> %d\n", element);
    }
}

// Remove an element from the queue (Dequeue)
int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty! Nothing to delete.\n");
        return -1;
    } else {
        element = items[front];
        // If there is only one element left, reset the queue pointers
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return element;
    }
}

// Display the elements of the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nFront index -> %d", front);
        printf("\nItems -> ");
        
        // Loop continuously from front until it reaches rear
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]); // Print the final (rear) element
        
        printf("\nRear index -> %d\n", rear);
    }
}

int main() {
    // Attempting dequeue on an empty queue
    dequeue();

    printf("\n--- Enqueuing Elements ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    // Attempting to enqueue when full
    enqueue(60); 

    display();

    printf("\n--- Dequeuing Elements ---\n");
    printf("Deleted element: %d\n", dequeue());
    printf("Deleted element: %d\n", dequeue());

    display();

    printf("\n--- Re-enqueuing after Dequeue (Circular Feature Check) ---\n");
    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
