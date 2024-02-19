#include <stdio.h>
#include <stdlib.h>

#define MAX 3
char cq[MAX];
int front = -1, rear = -1;

void insert(char item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\n\n~~Circular Queue Overflow~~");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        cq[rear] = item;
    }
}

void del() {
    char item;
    if (front == -1) {
        printf("\n\n~~Circular Queue Underflow~~");
    } else {
        item = cq[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("\n\nDeleted element from the queue is: %c ", item);
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("\n\nCircular Queue Empty");
    } else {
        printf("\nCircular Queue contents are:\n");
        printf("Front[%d]-> ", front);
        for (i = front; i != rear; i = (i + 1) %MAX) {
            printf(" %c", cq[i]);
        }
        printf(" %c", cq[i]);
    }
}

int main() {
    int ch;
    char item;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the character / item to be inserted: ");
                scanf(" %c", &item);
                insert(item);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\nPlease enter a valid choice");
        }
    }
    return 0;
}