/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Recent Changes:
    - Renamed `initialize()` to `initializeQueue()` 
    - Renamed `display()` to `displayQueue(Queue *q)` 
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

/*
Includes definitions:
    - typedef struct Queue {...} Queue;
    - Queue* initializeQueue();
    - int isFull(Queue *q);
    - int isEmpty(Queue *q);
    - int enqueue(Queue *q, int value);
    - int dequeue(Queue *q);
    - void display(Queue *q);

*/

// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Some Global Definitions
#define MAX 100

// Definition of Queue
typedef struct Queue {
    int array[MAX];
    int front, rear;
} Queue;

/* Allocates memory and initializes a `Queue` and returns its memory address. */
Queue* initializeQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    return q;
}

/* 
Checks if the Queue is full or not. Returns `1` if full, else returns `0` 
It takes the following parameters:
    - q (`Queue *`) : Pointer of the Queue

*/
int isFull(Queue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

/* 
Checks if the Queue is empty or not. Returns `1` if empty, else returns `0` 
It takes the following parameters:
    - q (`Queue *`) : Pointer of the Queue.
    
*/
int isEmpty(Queue *q) {
    return (q->front == -1);
}

/* 
Inserts a new value at the end of the queue. Returns `0` if successful, else returns `-1` 
It takes the following parameters:
    - q (`Queue *`) : Pointer of the Queue.
    
*/
int enqueue(Queue *q, int value) {
    if (isFull(q)) return -1;

    if (isEmpty(q)) q->front = 0;

    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = value;
    return 0;
}

/* 
Deletes value from the front of the queue. Returns the value it deleted if 
successful, else returns `INT_MIN` from `<limits.h>`. 
It takes the following parameters:
    - q (`Queue *`) : Pointer of the Queue.

*/
int dequeue(Queue *q) {
    if (isEmpty(q)) return INT_MIN;

    int value = q->array[q->front];

    if (q->front == q->rear) {  // If last element is dequeued
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

/* 
prints the Queue in an array like fashion. 
It takes the following parameters:
    - q (`Queue *`) : Pointer of the Queue.

*/
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("[]\n");
        return;    
    }

    printf("[");
    int i = q->front;
    while (1) {
        printf("%d, ", q->array[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("]\n");
}

