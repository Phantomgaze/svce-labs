#include <stdio.h>
#include <string.h>

int F(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '%':
            return 3;
        case '^':
        case '$':
            return 4;
        case '(':
            return 0;
        case '#':
            return -1;
        default:
            return 8;
    }
}

int G(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '%':
        case '^':
        case '$':
            return 6;
        case '(':
            return 9;
        case ')':
            return 0;
        default:
            return 7;
    }
}

void infix_postfix(char infix[], char postfix[]) {
    int top, j, i;
    char stack[30], symbol;
    top = -1;
    stack[++top] = '#';
    j = 0;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        while (F(stack[top]) > G(symbol)) {
            postfix[j] = stack[top--];
            j++;
        }
        if (F(stack[top]) != G(symbol)) {
            stack[++top] = symbol;
        } else {
            top--;
        }
    }
    while (stack[top] != '#') {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[20], postfix[20];
    printf("\nEnter a valid infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix_postfix(infix, postfix);
    printf("\nThe infix expression is: %s", infix);
    printf("\nThe postfix expression is: %s", postfix);
    printf ("\nPress enter to exit...");

    getchar();
}