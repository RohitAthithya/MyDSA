
#include <iostream>

using namespace std;
// make custom data types
typedef short int basic_t;

// definition of a structure
typedef struct rectangle
{
    basic_t length;
    basic_t breadth;
} rectangle; // notice the ; operator at the end of the definition
// In C, if typedef is not used then we need to declare/intialise a struct type, with implicitly mentioning rectangle.
// In cpp, struct is optionals
struct student;
int main()
{
    rectangle a = {10, 20}; // declaring and initialising the structure here
    rectangle b;            // declaring structure only

    // notice how we are using the '.' operator to work on the declared structure variable
    b.breadth = 40; // notice how we have updated the values of the structure here
    b.length = 10;

    cout << "legnth and breadth of rectangle 'a' is : " << a.length
         << " units and " << a.breadth << " units respectively " << endl;

    rectangle *pb = &b; // pointer to the declared structure b

    // notice how we have used the arrow operator to access the contents of the structure b
    cout << "accessing values using pointers" << endl;
    cout << "legnth and breadth of rectangle 'b' is : " << (*pb).length
         << " units and " << (*pb).breadth << " units respectively " << endl;
    cout << "legnth and breadth of rectangle 'b' is : " << pb->length
         << " units and " << pb->breadth << " units respectively " << endl;

    // turn this on when running the struct student
    //  cout << "details of student 2 are: " << endl;
    //  cout << "Name :" << db[1].name << endl;
    //  cout << "Roll no. :" << db[1].roll_num << endl;
    //  cout << "Dept :" << db[1].dept << endl;
    //  cout << "Addr :" << db[1].addr << endl;

    // allocatiing memory in heap for strcut type variables
    // and different ways of referencing the content pointed by the structure

    // In C:
    rectangle *pRect3;
    pRect3 = (rectangle *)malloc(sizeof(rectangle));
    pRect3[0].length = (*pb).length + 10; // notice that if we use a different index on the pRect3[x] then, we will get a garbage value!
    pRect3->breadth = pb->breadth + 20;
    cout << "legnth and breadth of rectangle 'Rect3' is : " << pRect3->length
         << " units and " << pRect3->breadth << " units respectively " << endl;

    // In C++:
    rectangle *pRect4;
    pRect4 = new rectangle;
    pRect4[0].length = 99;
    pRect4->breadth = -99;
    cout << endl
         << "legnth and breadth of rectangle 'Rect4' is : " << pRect4->length
         << " units and " << pRect4->breadth << " units respectively " << endl;

    // C++
    // array of structures
    // rectangle *pSetOfRectangles;
    // pSetOfRectangles = new rectangle[3];
    // (pSetOfRectangles + 0 * sizeof(pSetOfRectangles))->breadth = 2;
    // (pSetOfRectangles + 0 * sizeof(pSetOfRectangles))->length = 4;
    // (pSetOfRectangles + 1 * sizeof(pSetOfRectangles))->breadth = 3;
    // (pSetOfRectangles + 1 * sizeof(pSetOfRectangles))->length = 6;
    // (pSetOfRectangles + 2 * sizeof(pSetOfRectangles))->breadth = 4;
    // (pSetOfRectangles + 2 * sizeof(pSetOfRectangles))->length = 8;

    // for (basic_t iter = 0; iter < 3; iter++)
    // {
    //     cout << "Details of Rect " << iter + 1 << endl
    //          << "\tBreadth :" << (pSetOfRectangles + iter * sizeof(pSetOfRectangles))->breadth << endl
    //          << "\tLength :" << (pSetOfRectangles + iter * sizeof(pSetOfRectangles))->breadth << endl
    //          << "--------------" << endl;
    // }

    rectangle *pSetOfRectangles;
    pSetOfRectangles = new rectangle[3];
    (pSetOfRectangles + 0)->breadth = 2;
    (pSetOfRectangles + 0)->length = 4;
    (pSetOfRectangles + 1)->breadth = 3;
    (pSetOfRectangles + 1)->length = 6;
    (pSetOfRectangles + 2)->breadth = 4;
    (pSetOfRectangles + 2)->length = 8;

    for (basic_t iter = 0; iter < 3; iter++)
    {
        cout << "Details of Rect " << iter + 1 << endl
             << "\tBreadth :" << (pSetOfRectangles + iter)->breadth << endl
             << "\tLength :" << (pSetOfRectangles + iter)->breadth << endl
             << "--------------" << endl;
    }
    return 0;
}

/* Similarly we can use strcutures to represent a variety of data types*/

// example of a imaginary number as it has two parts, the real and the imaginary part
struct imaginary
{
    double real;
    double imag; // imaginary part of the structure
};

// example of a student :
//  the possible parameters defining a student are:
//  roll no. [needs a int of max size 1000],
// name [needs a string of 50 characters],
// department [needs a string of max 20 characters],
// address [needs a long string of almost 100 characters]

struct student
{
    basic_t roll_num;
    char name[50];
    char dept[20];
    char addr[100];
};

// note that the size of this structure would be 171 bytes , as basic_t is of type short int => each 1 byte

/// we can go for any array of structures
// for e.g. there a re two students

struct student db[3] = {
    {1, "rohit", "EEE", "24, granyle road, virigina beach"},
    {2, "rohit", "EEE", "25, granyle road, virigina beach"},
    {3, "rohit", "EEE", "246, granyle road, virigina beach"},
};