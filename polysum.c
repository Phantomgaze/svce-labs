#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int expo, coef;
    struct node *next;
} node;

node *insert(node *head, int expo, int coef) {
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    if (!p) return NULL; // Check for malloc failure
    p->expo = expo;
    p->coef = coef;
    p->next = NULL;
    if (head == NULL) {
        p->next = p; // Create a circular list with a single node
        return p;
    }
    if (expo > head->expo) {
        p->next = head->next;
        head->next = p;
        return p; // New head
    }
    if (expo == head->expo) {
        head->coef += coef;
        return head;
    }
    q = head;
    while (q->next != head && expo < q->next->expo) {
        q = q->next;
    }
    if (expo == q->expo) {
        q->coef += coef;
    } else {
        p->next = q->next;
        q->next = p;
    }
    return head;
}

node *create() {
    int n, expo, coef;
    node *head = NULL;
    printf("\nEnter number of terms of polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter coef & expo: ");
        scanf("%d%d", &coef, &expo);
        head = insert(head, expo, coef);
    }
    return head;
}

node *add(node *p1, node *p2) {
    node *head = NULL;
    printf("\nAddition of polynomial: ");
    node *p = p1;
    do {
        head = insert(head, p->expo, p->coef);
        p = p->next;
    } while (p != p1);
    p = p2;
    do {
        head = insert(head, p->expo, p->coef);
        p = p->next;
    } while (p != p2);
    return head;
}

int eval(node *head) {
    int x, ans = 0;
    printf("\nEnter the value of x: ");
    scanf("%d", &x);
    node *p = head;
    do {
        ans += p->coef * pow(x, p->expo);
        p = p->next;
    } while (p != head);
    return ans;
}

void display(node *head) {
    if (!head) {
        printf("Empty polynomial\n");
        return;
    }
    node *p = head;
    do {
        printf("%s%d*x^%d ", (p != head) ? " + " : "", p->coef, p->expo);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main() {
    int ch;
    node *p1 = NULL, *p2 = NULL, *p3 = NULL;
    while (1) {
        printf("\nPolynomial Operations:\n1. Add\n2. Evaluate\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nCreating first polynomial:\n");
                p1 = create();
                display(p1);
                printf("\nCreating second polynomial:\n");
                p2 = create();
                display(p2);
                p3 = add(p1, p2);
                printf("\nResultant polynomial after addition:\n");
                display(p3);
                break;
            case 2:
                printf("\nCreating polynomial for evaluation:\n");
                p1 = create();
                display(p1);
                int a = eval(p1);
                printf("\nValue of polynomial: %d\n", a);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}