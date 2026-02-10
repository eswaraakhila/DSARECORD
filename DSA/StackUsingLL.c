/*
    AIM:
    ----
    To implement a Stack using a Linked List and perform basic
    stack operations such as PUSH, POP, and DISPLAY.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Create a structure 'node' with:
                - data (stores value)
                - next (pointer to next node)

    PUSH(x):
    --------
    Step P1: Create a new node using malloc
    Step P2: Assign newnode->data = x
    Step P3: newnode->next = top
    Step P4: Update top = newnode
    Step P5: End

    POP():
    ------
    Step PO1: If top == NULL
                    Print "Stack Underflow"
                    Return
    Step PO2: temp = top
    Step PO3: top = top->next
    Step PO4: Free temp
    Step PO5: End

    DISPLAY():
    ----------
    Step D1: If top == NULL
                    Print "Stack is empty"
                    Return
    Step D2: Set temp = top
    Step D3: While temp != NULL
                    Print temp->data
                    temp = temp->next
    Step D4: End

    Step 3: Stop
*/
#include <stdio.h>
#include <stdlib.h>

// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
};

// To create a node and it returns address of newly created node
struct Node *CreateNode(int data)
{
    // STACK = (char *)malloc(MAX * sizeof(char));
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data)
{
    struct Node *newElement = CreateNode(data);
    newElement->next = *top;
    *top = newElement;
    printf("Node with data %d pushed successfully  .\n", data);
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty/underflow, pop operation can't be performed");
        return;
    }

    struct Node *temp = *top;
    *top = temp->next;
    printf("Element %d popped from stack.\n", temp->data);
    free(temp);
    return;
}

void DisplayStack(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp;
    temp = top;
    printf("\nElements In Stack: [Top] ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *top = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
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
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            DisplayStack(top);
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
    
        

