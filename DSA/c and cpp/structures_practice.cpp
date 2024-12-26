
#include <iostream>

using namespace std;
// make custom data types
typedef short int basic_t;

// definition of a structure
struct rectangle
{
    basic_t length;
    basic_t breadth;
}; // notice the ; operator at the end of the definition

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
    cout << "legnth and breadth of rectangle 'b' is : " << pb->length
         << " units and " << pb->breadth << " units respectively " << endl;

    // turn this on when running the struct student
    //  cout << "details of student 2 are: " << endl;
    //  cout << "Name :" << db[1].name << endl;
    //  cout << "Roll no. :" << db[1].roll_num << endl;
    //  cout << "Dept :" << db[1].dept << endl;
    //  cout << "Addr :" << db[1].addr << endl;

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