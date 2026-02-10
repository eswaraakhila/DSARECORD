/*
    AIM:
    ----
    To implement a Doubly Linked List (DLL) and perform basic operations
    such as insertion, deletion, and traversal in both forward and backward directions.

    ALGORITHM:
    ----------

    Step 1: Start
    Step 2: Create a structure 'node' with:
                - data  (stores value)
                - prev  (pointer to previous node)
                - next  (pointer to next node)

    INSERT AT BEGINNING(x):
    ------------------------
    Step IB1: Create a new node
    Step IB2: newnode->data = x
    Step IB3: newnode->prev = NULL
    Step IB4: newnode->next = head
    Step IB5: If head != NULL
                    head->prev = newnode
    Step IB6: head = newnode
    Step IB7: End

    INSERT AT END(x):
    ------------------
    Step IE1: Create a new node
    Step IE2: newnode->data = x
    Step IE3: newnode->next = NULL
    Step IE4: If head == NULL
                    newnode->prev = NULL
                    head = newnode
                    End
    Step IE5: Traverse the list until last node
    Step IE6: last->next = newnode
    Step IE7: newnode->prev = last
    Step IE8: End

    DELETE AT BEGINNING:
    ---------------------
    Step DB1: If head == NULL
                    Print "List Empty"
                    End
    Step DB2: temp = head
    Step DB3: head = head->next
    Step DB4: If head != NULL
                    head->prev = NULL
    Step DB5: Free temp
    Step DB6: End

    DELETE AT END:
    ---------------
    Step DE1: If head == NULL
                    Print "List Empty"
                    End
    Step DE2: Traverse to last node
    Step DE3: temp = last
    Step DE4: If last->prev == NULL
                    head = NULL
                    Free temp
                    End
    Step DE5: last->prev->next = NULL
    Step DE6: Free temp
    Step DE7: End
*/
#include <stdio.h>
#include <stdlib.h>

// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
    struct Node *prev; // To hold the address of previous node
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
    newNode->prev = NULL;
    return newNode;
}

void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    newNode->next = *head;
    newNode->prev = NULL; // Optional
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    printf("Node with data %d inserted at beginning successfully  .\n", data);
}

void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with data %d inserted at the end successfully.\n", data);
}

void InsertAtPosition(struct Node **head, int data, int position)
{
    // Considering that the position starts from 1 (Head at 1)
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;
    for (int k = 1; (k < position - 1 && temp != NULL); k++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }

    // Only when given position is valid
    struct Node *newNode = CreateNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)         // Only if NOT inserting at the end
        temp->next->prev = newNode; // Correct linking for DLL

    temp->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete a node by value
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("Linked List is empty, deletion operation can't be performed");
        return;
    }

    struct Node *temp = *head;

    // If head itself holds the value
    if (temp->data == valueToDelete)
    {
        *head = temp->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    // Search for the value
    struct Node *before = *head;
    while (before->next != NULL)
    {
        if (before->next->data == valueToDelete)
        {
            temp = before->next;
            before->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = before;

            free(temp);
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        before = before->next;
    }
    printf("Element %d not found.\n", valueToDelete);
    return;
}

// Display all elements
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp;
    temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        printf(" |Prev=%p|%d|Next=%p| -> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data and position to insert: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;
        case 5:
            DisplayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
