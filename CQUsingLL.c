/*
    AIM:
    ----
    To implement a Circular Queue using Linked List and perform the
    operations ENQUEUE, DEQUEUE, and DISPLAY.

    ALGORITHM:
    ----------

    Step 1: Start
    Step 2: Define a node structure with:
                - data
                - next (pointer to next node)

    ENQUEUE(x):
    -----------
    Step E1: Create a new node
    Step E2: newnode->data = x
    Step E3: If front == NULL
                    front = rear = newnode
                    rear->next = front   // circular link
             Else
                    rear->next = newnode
                    rear = newnode
                    rear->next = front
    Step E4: End

    DEQUEUE():
    ----------
    Step D1: If front == NULL
                    Print "Queue Underflow"
                    Return
    Step D2: temp = front
    Step D3: If front == rear
                    front = rear = NULL   // Only one element
             Else
                    front = front->next
                    rear->next = front    // maintain circular link
    Step D4: Free temp
    Step D5: End

    DISPLAY():
    ----------
    Step S1: If front == NULL
                 Print "Queue is empty"
                 Return
    Step S2: Set temp = front
    Step S3: Do
                 Print temp->data
                 temp = temp->next
             While temp != front
    Step S4: End

    Step 3: Stop
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    if (front == NULL && rear == NULL) //Queue empty
    {
        front = rear = newNode;
        newNode->next = front; //Circular link
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }

    printf("%d inserted into circular queue.\n", item);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) // Only one node
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display operation
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
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
