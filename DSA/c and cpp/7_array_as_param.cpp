// passing an array as a parameter
// note: python lists are not arrays
// pass base address of an array as input to the function
// usually the length of array is also mentioned, as it is decided by the user:
// array in itself does not have the info of its length

// arrays can be only be pass by address, it can not be passed by value nor passed by reference

#include <iostream>
using namespace std;
typedef short int basic_t;

void fun(int Array[], int n)
{
    int i;
    cout << " buggy number of elements are: " << sizeof(Array) / sizeof(int) << endl;
    for (i = 0; i < n; i++)
    {
        Array[i] *= 2; // notice how the actual memory is changed, ofcourse, it's a pointer based operation
    }

    // check out what happens if we use the foreach loop in this pointer to array
    // for (int a : Array)
    // {
    //     cout << a << endl; //lol, errored out: std::begin and end are not known, this is because: Array here is a pointer and not an array
    // }
}

/**
 * Create and initialise the array with 0s
 */
int *createArray(int sizeOfArray)
{
    int *p;
    p = (int *)malloc(sizeOfArray * sizeof(*p));
    // p = new int[sizeOfArray]; //C++ way
    for (basic_t i = 0; i < sizeOfArray; i++)
        p[i] = 0;

    return p;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    cout << sizeof(array) / sizeof(int) << endl;
    // this above statement in the method: fun, produces a different output! compare and check why: hint-> pass by address only!

    fun(array, 5);

    for (basic_t i = 0; i < 5; i++)
    {
        cout << array[i] << endl;
    }

    cout << "New Array is being created here:" << endl;
    int *pNewArray = createArray(2);
    cout << pNewArray[1] << endl;
    cout << pNewArray[2] << endl; // must show gbg. value

    return 0;
}