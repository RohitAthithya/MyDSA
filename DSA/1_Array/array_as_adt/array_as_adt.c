/**
 * Array ADT: Array as an Abstract Data type
 *
 * Data and the Array related operations:
 * some possible operations are:
 * 1. Display array
 * 2. Add or append
 * 3. Insert at an index
 * 4. Delete an element
 * 5. Search for an element
 * 6. Get element at given index
 * 7. Set value at given index
 * 8. max or min value in the array
 * 9. reverse the array
 * 10. Shift / rotate the array
 */

#include <stdio.h>
#include <stdlib.h>

// structure holds the Array ADT
// restricting the type of the array it holds to int
typedef struct Array_ADT
{
    int *arr;   // stores elements
    int size;   // stores the max. permissible size of the array: arr
    int length; // stores the number of elements in the array
} Array;

// function used
void printArray(struct Array_ADT);

int main()
{
    int n;

    // 1. create a sample Array_ADT
    Array arr;
    printf("Enter the size of array required:\n");
    scanf("%d", &arr.size); // store the required size in the member arr.size
    arr.size = 10;
    // allocate the array based on the required size
    arr.arr = (int *)malloc(arr.size * sizeof(*arr.arr));
    arr.length = 0;

    // 2. Initialise the array with the elements from the user
    printf("Enter the Number of numbers:\n");
    // scanf("%d", &n);
    n = 5;
    arr.length = n;
    printf("Enter the array elements in each line:\n");
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", &(arr.arr[i]));
        arr.arr[i] = i + 1;
    }

    // print the array to o/p
    printArray(arr);

    return 0;
}

void printArray(struct Array_ADT arr)
{
    for (int i = 0; i < arr.length; i++) // it is enough to iterate over just the arr.length not the arr. size
    {
        printf("%d\t", arr.arr[i]);
    }
    return;
}