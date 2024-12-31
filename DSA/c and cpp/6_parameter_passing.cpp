// passing parameters:

#include <iostream>
using namespace std;

// swap
//  1. pass by value
// suitable when a resultant data is required after some computation or useful processing
// does not perfrom direct operation on memory
void swap1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// swap
//  2. pass by address
//
void swap2(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// swap
//  3. pass by reference
// note that when a function utilises pass by reference, then it's machine code is copied to the caller's machine code
// this is what ensures that the caller's activation record/stack frame is avilable for the function's activation record
// thus enabling the referencing of variables [copying of mahcine code to caller's machine code = inlining of a function]
// NOTE:
// 1. Function utilising pass by reference are generally not encouraged due to the above given reason, as the function
// 2. The compiler MAY convert to this function into a inline function OR
// the compiler MAY choose to convert the referencing into pointer operation internally!

// NOTE: INLINE is just a suggestion to the compiler rather than a strict implementation.
void swap3(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    a = 10;
    b = 20;
    // swap1(a, b);
    // swap2(&a, &b);
    swap3(a, b);
    cout << "a = " << a << "  |  b = " << b << endl;
}