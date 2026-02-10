/*
    AIM:
    ----
    To write a C program to search for an element in a sorted array
    using Binary Search (Iterative method).

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Read the size of the array 'n'
    Step 3: Read 'n' sorted elements into the array
    Step 4: Read the element to be searched (key)
    Step 5: Initialize low = 0, high = n - 1
    Step 6: Repeat while low <= high
                Step 6.1: mid = (low + high) / 2
                Step 6.2: If array[mid] == key
                              Print "Element found"
                              Stop
                Step 6.3: Else If key < array[mid]
                              high = mid - 1
                Step 6.4: Else
                              low = mid + 1
            End While
    Step 7: If low > high
                Print "Element not found"
    Step 8: Stop
*/
#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;
    printf("Enter the size of array: ");
    scanf("%d",&size);
   

    int searchSpace[size];

    //Reading elements into array
    for(int i=0;i<size;i++)
    {
        printf("Enter element %d of %d: ",i, size-1);
        scanf("%d",&searchSpace[i]);
    }

    printf("Enter the element to search ");
    scanf("%d",&targetElement);

    start = 0;
    end = size-1;

    while (start<=end)
    {
        mid = (start + end)/2;
        if(searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid+1);
            return 0;
        }
        else if(searchSpace[mid] < targetElement)
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("ELement doesn't exist in the given search set");
    
   return 0;
}
