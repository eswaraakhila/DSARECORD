/*
    AIM:
    ----
    To implement Quick Sort in C using the divide-and-conquer technique.

    ALGORITHM:
    ----------
    Step 1: Start
    Step 2: Choose the last element as pivot
    Step 3: Partition the array such that:
                - Elements smaller than pivot are on the left
                - Elements greater than pivot are on the right
    Step 4: Recursively apply Quick Sort on:
                - Left sub-array
                - Right sub-array
    Step 5: Stop
*/
#include <stdio.h>

//Swap the numbers / Call by referene to persist changes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition 
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
