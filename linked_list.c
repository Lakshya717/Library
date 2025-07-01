/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Library of `Fully Dynamic Linked List (LL)`
To initiate a new LL,
    1. Create a new `Node` pointer assigned to `NULL`
    2. Start appending to this Node using `append()` function. 
       (It will take care of allocating memory and initializing and stuff...)

Recent Changes:
    - Renamed `display()` to `displayLL()` 
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

/*
Includes Definitions:
    - typedef struct Node {...} Node;
    - Node * createNode(int value);
    - Node* append(Node *head, int value);
    - void displayLL(Node *head);
    - void freeNodes(Node *head);
    - Node* insertAt(Node *head, int index, int value);
    - int deleteAt(Node **head, int index);
*/

// Standard Libraries
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
typedef struct Node {
    int data;
    struct Node *next; 
} Node;

/* 
Returns a pointer to a node created with the passed input.
    - value (int): data to hold in the node
*/ 
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* 
Inserts a new value at the end of the linked list.
    - head (Node*): pointer to the head of the linked list
    - value (int): data to hold in the node
Returns the pointer to the new modified head.
*/ 
Node* append(Node *head, int value) {
    Node *newNode = createNode(value); 

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    return head;
}

/* 
Prints the linked list in a linear array fashion.
    - head (Node*): pointer to the head of the linked list
*/ 
void displayLL(Node *head) {
    printf("[");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

/* 
Frees all the nodes in the linked list.
    - head (Node*): pointer to the head of the linked list 
*/ 
void freeNodes(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        Node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}

/* 
Inserts a new value in the linked list at the specified index.
    - head (Node*): pointer to the head of the linked list 
    - index (int): position at which the new node should be inserted 
    - value (int): data to insert
Returns the pointer to the new modified head.
*/ 
Node* insertAt(Node *head, int index, int value) {
    Node *newNode = createNode(value);

    if (head == NULL || index == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    int pos = 0;

    while (pos < index - 1) {
        if (temp == NULL) return head;  // Index out of range
        temp = temp->next;
        pos++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

/* 
Deletes a node in the linked list at the specified index.
    - head (Node**): double pointer to the head of the linked list 
    - index (int): index of the node to delete
Returns 0 when successful, else returns -1 (e.g., index out of range).
*/ 
int deleteAt(Node **head, int index) {
    if (*head == NULL) return -1;  // List is empty

    Node *temp = *head;

    if (index == 0) {
        *head = temp->next;
        free(temp);
        return 0;
    }

    int pos = 0;
    while (pos < index - 1) {
        if (temp == NULL || temp->next == NULL) return -1; // Index out of range
        temp = temp->next;
        pos++;
    }

    if (temp->next == NULL) return -1; // Nothing to delete

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return 0;
}