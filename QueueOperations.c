/*
    AIM:
    ----
    To implement Queue operations such as ENQUEUE, DEQUEUE, PEEK,
    and DISPLAY using an array.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Initialize front = -1, rear = -1

    ENQUEUE(x):
    -----------
    Step E1: If rear == maxsize - 1
                 Print "Queue Overflow"
                 Return
    Step E2: If front == -1
                 front = 0
    Step E3: rear = rear + 1
    Step E4: queue[rear] = x

    DEQUEUE():
    ----------
    Step D1: If front == -1 OR front > rear
                 Print "Queue Underflow"
                 Return
    Step D2: item = queue[front]
    Step D3: front = front + 1
    Step D4: Print item removed

    PEEK():
    -------
    Step P1: If front == -1 OR front > rear
                 Print "Queue is empty"
                 Return
    Step P2: Print queue[front]

    DISPLAY():
    ----------
    Step S1: If front == -1 OR front > rear
                 Print "Queue is empty"
                 Return
    Step S2: For i = front to rear
                 Print queue[i]
    Step S3: End

    Stop
*/
#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;
int *QUEUE; // Dynamic array for queue

void enqueue(int item)
{
    if (rear == size - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if (front == -1) // First element insertion
        front = 0;

    rear++;
    QUEUE[rear] = item;
    printf("%d inserted into queue.\n", item);
}

void dequeue()
{

    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int temp = QUEUE[front];
    front++;
    printf("Deleted element: %d\n", temp);

    // Reset queue when empty
    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;

    printf("Enter size of Queue: ");
    scanf("%d", &size);

    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
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
            free(QUEUE);
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
