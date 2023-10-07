#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    pq->front = NULL;
    return pq;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (pq->front == NULL || pq->front->priority > priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node* current = pq->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        fprintf(stderr, "Priority queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return data;
}

void display(PriorityQueue* pq) {
    Node* current = pq->front;
    while (current != NULL) {
        printf("%d (priority: %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

void freePriorityQueue(PriorityQueue* pq) {
    Node* current = pq->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(pq);
}

int main() {
    PriorityQueue* pq = createPriorityQueue();

    // Enqueue elements with priority
    enqueue(pq, 10, 2);
    enqueue(pq, 20, 1);
    enqueue(pq, 30, 3);

    printf("Priority queue elements: ");
    display(pq);

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(pq));
    printf("Dequeued element: %d\n", dequeue(pq));

    printf("Priority queue elements after dequeue: ");
    display(pq);

    // Free memory
    freePriorityQueue(pq);

    return 0;
}
