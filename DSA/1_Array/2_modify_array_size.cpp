/**
 *
 * The goal of this file is to describe the available options to modify the size of an array in C/C++.
 *
 * This file shows two ways to modify the size [increase in size]
 *  1. using another pointer, new memory allocation, copying content to newer memory, resassigning pointer to
 *      newer location
 *  2. using the realloc function from the
 *
 * new: use of memcpy function from the library memory
 */

#include <iostream>
#include <memory.h>
using namespace std;

// 1. Creating a new  array with required size
//  copy the content and reassign the old pointer to the new array
int main()
{
    // create an array first
    int *pArr_1 = new int[5];

    // intialize the array - thus forming the 'old' array
    for (int temp = 0; temp < 5; temp++)
    {
        pArr_1[temp] = temp + 1;
    }

    // 1. create a new array with the required size
    int *pArr_2 = new int[10];

    // 2. copy the content from old to new array
    memcpy(pArr_2, pArr_1, 5 * sizeof(*pArr_1));
    // or we can just use the for cloop to copy the content
    // for (int temp = 0; temp < 5; temp++)
    // {
    //     pArr_2[temp] = pArr_1[temp];
    // }

    // [Opt 2.1] Print the new array to check the contents
    cout << "New array contents: ";
    for (int temp = 0; temp < 10; temp++)
    {
        cout << pArr_2[temp] << " ";
    }

    // 3. Delete the old array - else memory leak occurs
    delete[] pArr_1;
    // free(pArr_1);

    // 4. Reassign the old pointer to the new array
    pArr_1 = pArr_2;
    pArr_2 = NULL; // we dont need two pointers to the newly allocated memory

    // 5. check the content of the old pointer
    cout << "Modified array contents: ";
    for (int temp = 0; temp < 10; temp++)
    {
        cout << pArr_1[temp] << " ";
    }

    return 0;
}

// 2. method 2 is to use the realloc method that just increases the size automatically
//  here we do not need to create a new array and no need to copy the values of the existing array to the newly created one!

// int main()
// {
//     int *pArr_1;
//     pArr_1 = (int *)malloc(5 * sizeof(*pArr_1));
//     // intialize the array - thus forming the 'old' array
//     for (int temp = 0; temp < 5; temp++)
//     {
//         pArr_1[temp] = temp + 1;
//     }
//     for (int temp = 0; temp < 10; temp++)
//     {
//         cout << pArr_1[temp] << " ";
//     }
//     pArr_1 = (int *)realloc(pArr_1, 10 * sizeof(*pArr_1));
//     cout << endl
//          << "New array contents: " << endl;
//     for (int temp = 0; temp < 10; temp++)
//     {
//         cout << pArr_1[temp] << " ";
//     }

//     // print and check the content of the extened space, notice changes!
//     // clearly we can tell how much memory was allocated to the array!
//     return 0;
// }