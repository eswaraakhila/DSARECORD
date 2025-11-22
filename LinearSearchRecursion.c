/*
    AIM:
    ----
    To write a C program to search an element in an array using
    Linear Search (Recursive method) and display whether the element is found.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Read the size of the array 'n'
    Step 3: Read 'n' elements into the array
    Step 4: Read the element to be searched (key)
    Step 5: Call the recursive function linearSearch(arr, key, index, n)

            Function linearSearch(arr, key, index, n):
                Step 6: If index >= n
                           Return -1   // Not found
                Step 7: If arr[index] == key
                           Return index   // Found
                Step 8: Else
                           Return linearSearch(arr, key, index + 1, n)
    Step 9: In main, check the return value:
                If returned value == -1
                    Print "Element not found"
                Else
                    Print "Element found at position"
    Step 10: Stop
*/
#include <stdio.h>
#include <stdbool.h>

int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    if (index >= size)
    {
        return -1;
    }
    if (dataSet[index] == elementToFind)
    {
        return index;
    }
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);

    int searchSpace[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);

    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);
}
