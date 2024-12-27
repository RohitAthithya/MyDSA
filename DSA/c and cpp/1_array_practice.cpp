#include <iostream>
// #include <stdio.h>

using namespace std;

typedef short int basic_t;

int main()
{

    // in the main memory, we have a segment called stack, the arrays that are defined or declared are initialised here.

    basic_t arr[5] = {0}; // this is initialised with garbage values
    // if additional values are given in the array then the
    arr[6] = 999;
    // declaration and definitions
    int B[5] = {2, 3}; // if all the elements of the array are not initialised then the remaining elements are made 0 instead of a garbage value

    *(B + 3) = -123;
    // accessing an array
    cout << "size of arr is :" << sizeof(arr) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "elem of arr @ " << i + 1 << " is : " << arr[i] << endl;
        cout << "elem of B @ " << i + 1 << " is : " << B[i] << endl;
        // printf("%d\n", B[i]);
        // printf("%d\n", *(B + i));
        // printf("%d\n\n", *(arr + i));
    }

    for (int x : B)
    {
        cout << "x = " << x << endl;
    }

    cout << arr[4] << " " << arr[5] << " " << arr[6] << endl;

    cout << "----------------------" << endl;

    basic_t n;
    cout << "enter size: ";
    cin >> n;
    int A[n]; // we can initialise such arrays in the latest c complires but were not allowed in the older ones.
    // people used to do the malloc or the calloc in c lang and the new operator in the c++ lang ??

    A[0] = 99;

    for (auto c : A)
    {
        cout << c << endl;
    }
    // note the output that, all the other uninitialised elements will be garbage values
    return 0;
}
