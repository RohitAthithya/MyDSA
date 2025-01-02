#include <iostream>
using namespace std;

typedef struct rectangle
{
    int length;
    int breadth;
} rectangle;

// using pass by value
int areaOfRectangle1(rectangle r1) // note that this s a formal parameter - we a re doing a pass by value
{
    return r1.length * r1.breadth;
}

// using pass by reference
int areaOfRectangle2(rectangle &r1) // note that this s a formal parameter - we a re doing a pass by value
{
    return r1.length * r1.breadth;
}

// using pass by address
int areaOfRectangle3(rectangle *r1) // note that this s a formal parameter - we a re doing a pass by value
{
    return r1->length * r1->breadth;
}

// structure with array as a data structure
typedef struct test1
{
    int arr[5];
    int n;
} test1;

// operating on structure with array in it
// note that because this is a struct, the values within it are passed by value ! everything will be copied to the function's
// activation record - compiler will do this copying automatically!
void fun(test1 t1)
{
    t1.arr[0] = -99;
    t1.arr[2] = -99;
    t1.arr[4] = -99;
    cout << "inside fun struct.arr is : " << t1.arr << endl;
    for (auto i : t1.arr)
        cout << "i = " << i << endl;
}
// same as fun but using pass by address
void fun1(test1 *t1)
{
    t1->arr[0] = -99;
    t1->arr[2] = -99;
    t1->arr[4] = -99;
    cout << "the modified struct.arr is : " << t1->arr << endl;
    for (auto i : t1->arr)
        cout << "i = " << i << endl;
}

int main()
{
    rectangle r1 = {10, 20};
    // int area = areaOfRectangle1(r1);
    // int area = areaOfRectangle2(r1);
    int area = areaOfRectangle3(&r1);

    cout << "area of rectangle is :" << area << endl;

    test1 newStruct = {{1, 2, 3, 4, 5}, 5};
    cout << "main: before fun struct.arr is : " << newStruct.arr << endl;
    for (auto i : newStruct.arr)
        cout << "i = " << i << endl;
    fun(newStruct);
    // fun1(&newStruct);
    cout << "main: after fun struct.arr is : " << newStruct.arr << endl;
    for (auto i : newStruct.arr)
        cout << "i = " << i << endl;
    return 0;
}
