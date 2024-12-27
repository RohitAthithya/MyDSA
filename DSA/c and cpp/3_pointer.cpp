#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *pA; // declaration of pointer variable
    pA = &a; // initialisatin of pointer variable
    printf("value at a is : %d\nA", a);
    printf("value at a is : %d\n", *pA); // dereferencing of pointer variable's content.
    // the pointer's type of data stored at the locations starting at the address denoted by pointer's value is returned

    // allocating memory in the heap segment
    // C lang
    int *pArray;

    printf("size of array is %lu\n", sizeof(*pArray));
    pArray = (int *)malloc(5 * sizeof(*pArray));
    printf("Memory allocated!\n");
    *(pArray + 0) = -99;
    printf("element at index 1: %d\n", *pArray);

    // C++ lang
    int *pArray2 = new int[5]; // need not type case it explicitly like in c
    printf("Memory allocated in another segment!\n");
    *(pArray2 + 0) = -77;
    printf("element at index 1: %d\n", *pArray2);

    // note that the memory in the heap segment is not deallocated yet!
    //  we provide delete keyword or the free keyword

    // C lang
    free(pArray);

    // C++ lang
    delete[] pArray2;

    return 0;
}

// in small programs, the deallocation is not done - no issues
// but if the programs are huge then, if allocated memory is NOT freed -> causes a lot of memory issues!