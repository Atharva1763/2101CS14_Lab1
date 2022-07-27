#include <stdio.h>

void swap(int *a, int *b);

//--------------Quick Sort-----------------//
int partition(int array[], int lo, int hi);
void quickSort(int array[], int lo, int hi);

//--------------Merge Sort-----------------//
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

//--------------Bubble Sort-----------------//
void bubbleSort(int arr[], int n);

//--------------Selection Sort-----------------//
void selectionsort(int array[], int n);

//--------------Insertion Sort-----------------//
void insertionsort(int arr[], int n);

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
    printf("Enter 2: Merge Sort\n");
    printf("Enter 3: Bubble Sort\n");
    printf("Enter 4: Selection Sort\n");
    printf("Enter 5: Insertion Sort\n");

    int operation;
    scanf( "%d" , &operation );
    
    switch(operation)
    {
        case 1:
            quickSort(arr, 0, n - 1);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        case 3:
            bubbleSort(arr,n);
            break;
        case 4:
            selectionsort(arr,n);
            break;
        case 5:
            insertionsort(arr,n);
            break;
    }
    
    printf("Sorted array in ascending order: \n");
    
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

//-----------------------------------------//
//--------------Quick Sort-----------------//
//-----------------------------------------//

void swap(int *a, int *b)         // function to swap elements
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int lo, int hi)        // function to find the partition position
{
    // selecting the rightmost element as pivot
    int pivot = array[hi];

    // pointer for greater element
    int i = (lo - 1);

    for (int j = lo; j < hi; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[hi]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int lo, int hi)
{
    if (lo < hi)
    {
        // find the pivot element such that elements smaller than pivot are on left of pivot and elements greater than pivot are on right of pivot

        int pi = partition(array, lo, hi);

        quickSort(array, lo, pi - 1);

        quickSort(array, pi + 1, hi);
    }
}

//-----------------------------------------//
//--------------Merge Sort-----------------//
//-----------------------------------------//


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int Left[n1], Right[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (Left[i] <= Right[j]) {
			arr[k] = Left[i];
			i++;
		}
		else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {                           //Copy the remaining elements of L[], if there are any
		arr[k] = Left[i];
		i++;
		k++;
	}
	
	while (j < n2) {                           // Copy the remaining elements of R[], if there are any 
		arr[k] = Right[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflo for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

//------------------------------------------//
//--------------Bubble Sort-----------------//
//------------------------------------------//

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//---------------------------------------------//
//--------------Selection Sort-----------------//
//---------------------------------------------//

void selectionsort(int array[], int n){
  for (int i = 0; i < n - 1; i++) {
    int index_of_min = i;
    for (int j = i + 1; j < n; j++) {
      // Select the minimum element in each loop.
      if (array[j] < array[index_of_min])
        index_of_min = j;
    }

    // put min at the correct position
    swap(&array[index_of_min], &array[i]);
  }
}


//---------------------------------------------//
//--------------Insertion Sort-----------------//
//---------------------------------------------//

void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}