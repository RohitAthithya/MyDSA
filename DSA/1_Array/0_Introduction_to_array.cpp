/** \file
 * Introduction to Array, declaring and initializing the array
 *
 * Array:
 * Collections of similar data types
 *
 * Variable:
 * A named memory location that store known data types
 *
 * Scalar:
 * A single variable
 *
 * Vector:
 * A collection of variables.
 *
 * Array can be visualized as a [vector] collection of variables/scalars
 * arranged in a linear fashion or contiuous memory location
 *
 */

#include <iostream>
using namespace std;

void printArray(int arr[], int size);

int main()
{
    // different ways to declare and initialise array
    //-------------------------------------------------

    // int arr[5]; // just declaring the array: mention the type and size
    // printArray(arr, 5);

    // int arr[5] = {1, 2, 3, 4, 5}; // initializing all the elements
    // printArray(arr, 5);

    // int arr[5] = {1, 2}; // initialzing a few elements, rest will be initialized to 0
    // printArray(arr, 5);

    // int arr[5] = {0}; // all the elements are initialized to 0
    // printArray(arr, 5);

    int arr[] = {1, 2, 3, 4, 5}; // the size of the R.H.S. will be the size of the array.
    printArray(arr, 5);

    // ways to access the member of an array
    arr[3] = -3;
    *(arr + 2) = -2;
    1 [arr] = -1;
    printArray(arr, 5);

    return 0;
}

/**
 * printArray:
 * \brief  print array content upto given size,
 * \param  arr statically allocated array's address
 *          size integeral size of the array / number of intended elements the array stores'
 * \return
 */
void printArray(int arr[], int size)
{
    cout << "values are :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";

        // print address to check the continguity
        cout << "\twith address: " << arr + i << endl; // notice that the compiler we are using is the cpp22, and the int size is 4B
    }
    cout << endl;
}