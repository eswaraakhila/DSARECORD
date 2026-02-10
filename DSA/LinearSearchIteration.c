/*
    AIM:
    ----
    To write a C program to search an element in an array using
    Linear Search (Iterative method) and display whether the element is found.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Read the size of the array 'n'
    Step 3: Read 'n' elements into the array
    Step 4: Read the element to be searched (key)
    Step 5: Set a flag = 0
    Step 6: Repeat for i = 0 to n-1
                If array[i] == key
                    Set flag = 1
                    Break the loop
             End For
    Step 7: If flag == 1
                Print "Element found"
            Else
                Print "Element not found"
    Step 8: Stop
*/
#include <stdio.h>
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d",&size);

    int searchSpace[size];
    for(i=0; i<=size-1; i++)
    {
        printf("Enter the %d out of %d element in data set: ",i+1, size);
        scanf("%d",&searchSpace[i]);
    }

    //printf("Given Dataset for Linear Search is: ");
    for(int i=0; i<size; i++)
    {
        printf("%d - ",searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d",&elementToFind);
    i =0;
    while(i<size)
    {
        if(searchSpace[i] == elementToFind)
        {
            printf("Required element %d is found in the dataset at position %d or index %d",elementToFind, i+1, i);
            return 0;
        }
        i++;
    }

    printf("Required element %d is NOT found in the dataset!!!",elementToFind);
}
