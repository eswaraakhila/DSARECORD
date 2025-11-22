/* 
    AIM:
    ----
    To write a C program to reverse a given string.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Read the input string
    Step 3: Initialize two variables: i = 0, j = length - 1
    Step 4: Repeat while i < j
                Swap string[i] and string[j]
                Increment i
                Decrement j
    Step 5: Print the reversed string
    Step 6: Stop
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

char pop()
{
    char temp = STACK[top];
    top = top - 1;
    return temp;
}

int main()
{
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);
    char input[size];
    STACK = (char *)malloc(size * sizeof(char));

    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", &input);

    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }

    printf("Reversed string is - \n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }
}


