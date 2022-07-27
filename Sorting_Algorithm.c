#include <stdio.h>

//--------------Quick Sort-----------------//
void swap(int *a, int *b);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);


int main()
{
    int n;
    printf("Enter the number of elements in the array : ");

    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number corresponding to the opperation that you want to perform\n");
    printf("Enter 1: Quick Sort\n");
    
    int operation;
    scanf( "%d" , &operation );
    
    switch(operation)
    {
        case 1:
            quickSort(arr, 0, n - 1);
            break;
    }
    
    printf("Sorted array in ascending order: \n");
    
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)         // function to swap elements
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)        // function to find the partition position
{

    // selecting the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that elements smaller than pivot are on left of pivot and elements greater than pivot are on right of pivot

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}
