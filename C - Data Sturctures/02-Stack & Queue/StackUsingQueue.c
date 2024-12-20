#include <stdio.h>

#define MAX_SIZE 100

// Queues implemented as arrays
int queue1[MAX_SIZE];
int queue2[MAX_SIZE];
int front1 = -1, rear1 = -1; // For queue1
int front2 = -1, rear2 = -1; // For queue2

// Queue helper functions
int isEmpty(int front, int rear) {
    return front == -1;
}

int isFull(int rear) {
    return rear == MAX_SIZE - 1;
}

void enqueue(int queue[], int *front, int *rear, int value) {
    if (isFull(*rear)) {
        printf("Queue Overflow\n");
        return;
    }
    if (*front == -1) *front = 0;
    queue[++(*rear)] = value;
}

int dequeue(int queue[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[*front];
    if (*front == *rear) {
        *front = *rear = -1; // Reset queue if it becomes empty
    } else {
        (*front)++;
    }
    return value;
}

// Stack using two queues
void push(int value) {
    enqueue(queue1, &front1, &rear1, value);
}

int pop() {
    if (isEmpty(front1, rear1)) {
        printf("Stack Underflow\n");
        return -1;
    }

    // Move all elements except the last from queue1 to queue2
    while (front1 != rear1) {
        enqueue(queue2, &front2, &rear2, dequeue(queue1, &front1, &rear1));
    }

    // Last element in queue1 is the top of the stack
    int poppedValue = dequeue(queue1, &front1, &rear1);

    // Swap queue1 and queue2
    int *tempFront = &front1, *tempRear = &rear1;
    front1 = front2;
    rear1 = rear2;
    front2 = *tempFront;
    rear2 = *tempRear;

    return poppedValue;
}

int top() {
    if (isEmpty(front1, rear1)) {
        printf("Stack is empty\n");
        return -1;
    }

    // Move all elements except the last from queue1 to queue2
    while (front1 != rear1) {
        enqueue(queue2, &front2, &rear2, dequeue(queue1, &front1, &rear1));
    }

    // Get the last element in queue1, which is the top of the stack
    int topValue = dequeue(queue1, &front1, &rear1);
    enqueue(queue2, &front2, &rear2, topValue);

    // Swap queue1 and queue2
    int *tempFront = &front1, *tempRear = &rear1;
    front1 = front2;
    rear1 = rear2;
    front2 = *tempFront;
    rear2 = *tempRear;

    return topValue;
}

int isStackEmpty() {
    return isEmpty(front1, rear1);
}

// Driver code
int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", top()); // Output: 30
    printf("Popped element: %d\n", pop()); // Output: 30
    printf("Top element: %d\n", top()); // Output: 20

    push(40);
    printf("Top element: %d\n", top()); // Output: 40
    printf("Popped element: %d\n", pop()); // Output: 40
    printf("Popped element: %d\n", pop()); // Output: 20
    printf("Popped element: %d\n", pop()); // Output: 10

    printf("Is stack empty: %s\n", isStackEmpty() ? "Yes" : "No"); // Output: Yes

    return 0;
}
