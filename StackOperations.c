/*
    AIM:
    ----
    To implement stack operations such as PUSH, POP, PEEK, and DISPLAY
    using an array.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Initialize top = -1 and define max size for the stack

    PUSH(x):
    --------
    Step P1: If top == maxsize - 1
                Print "Stack Overflow"
                Return
    Step P2: top = top + 1
    Step P3: stack[top] = x
    Step P4: End

    POP():
    ------
    Step PO1: If top == -1
                 Print "Stack Underflow"
                 Return
    Step PO2: item = stack[top]
    Step PO3: top = top - 1
    Step PO4: Print item removed
    Step PO5: End

    PEEK():
    -------
    Step PK1: If top == -1
                 Print "Stack is empty"
                 Return
    Step PK2: Print stack[top]
    Step PK3: End

    DISPLAY():
    ----------
    Step D1: If top == -1
                 Print "Stack is empty"
                 Return
    Step D2: For i = top to 0
                 Print stack[i]
    Step D3: End

    Step 3: Stop
*/
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int size;
char *STACK; // Dynamic Array

void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;
        STACK[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top];
        top = top - 1;
        printf("Element popped %c", temp);
    }
}

void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }
    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]);
    }
}

int main()
{
    int choice;
    char data;

    printf("Enter size of stack: ");
    scanf("%d", &size);
    STACK = (char *)malloc(size * sizeof(char));

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            DisplayStack();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
