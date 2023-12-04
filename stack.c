#include<stdio.h> 
#include<conio.h> 
#define MAX 4 
int stack[MAX],item; 
int ch, top =-1, count=0, status =0;

//PUSH FUNCTION
void push(int stack[],int item) 
{ 
    if( top == (MAX-1) ) 
    { 
        printf("\n\nStack Is Overflow"); 
    } 
    else 
    { 
        stack[++top] = item; 
        status++; 
    } 
} 

//POP FUNCTION
int pop(int stack[]) 
{ 
    int ret; 
    if(top == -1) 
    { 
        printf("\n\nStack is Underflow"); 
        return ret; 
    } 
    ret = stack[top--]; 
    status--; 
    return ret;
} 

//FUNCTION TO CHECK STACK IS PALINDROME OR NOT
void palindrome(int stack[]) 
{ 
    int i, temp; 
    temp = status; 
    status = 0; 
    for(i = 0; i < temp; i++) 
    { 
        if(stack[i] != pop(stack)) 
        { 
            count++; 
        } 
    } 
    if(temp == -count) 
    { 
        printf("\nStack contents are Palindrome"); 
    } 
    else 
    { 
        printf("\nStack contents are not palindrome"); 
    } 
} 

//FUNCTION TO DISPLAY STACK
void display(int stack[]) 
{ 
    int i; 
    printf("\nThe stack contents are:"); 
    if( top == -1 ) 
    { 
        printf("\n\nStack is Empty"); 
    } 
    else 
    { 
        for(i = top; i >= 0; i--) 
        { 
            printf("\n%d", stack[i]); 
        } 
    } 
} 

void main() 
{ 
    //clrscr(); 
   
    do 
    { 
        printf("\n\n-MAIN MENU \n"); 
        printf("1. PUSH (Insert) in the Stack\n"); 
        printf("2. POP (Delete) from the Stack\n"); 
        printf("3. PALINDROME check using Stack\n"); 
        printf("4. Exit (End the Execution)\n"); 
        printf("Enter Your Choice: "); 
        scanf("%d",&ch); 
        switch(ch) 
        { 
            case 1: printf("Enter a element to be pushed: "); 
            scanf("%d",&item); 
            push(stack, item); 
            break; 
            case 2:item=pop(stack); 
            display(stack); 
            break; 
            case 3:palindrome(stack); 
            break; 
            case 4:exit(0); 
            break; 
            default: printf("\nEND OF EXECUTION"); 
        } 
    }while(ch != 4); 
    getch(); 
}
