#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

int isFull(struct Deque* deque) {
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1));
}

int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

void insertFront(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->arr[deque->front] = value;
}

void insertRear(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->arr[deque->rear] = value;
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int value = deque->arr[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return value;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int value = deque->arr[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return value;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = deque->front;

    do {
        printf("%d ", deque->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct Deque* deque = createDeque();

    insertFront(deque, 1);
    insertRear(deque, 2);
    insertFront(deque, 3);
    insertRear(deque, 4);

    printf("Deque elements: ");
    display(deque);

    printf("Deleted from front: %d\n", deleteFront(deque));
    printf("Deleted from rear: %d\n", deleteRear(deque));

    printf("Deque elements after deletion: ");
    display(deque);

    free(deque);
    return 0;
}