// functions in c/c++ programming

// grouping data is structures
// grouping instructions are called functions
// terminologies
// signature/prototype of function
// decalration of function
// parameters [active and formal]
// difference between monolithic programming and modular/procedural programming
// in cpp we have one step higher - object oriented programming
// writing >1000 lines of code in the main function is really bad style of coding
// refer CLEAN code for more info on why we need functions

#include <iostream>
using namespace std;

// prototype of the add function
int add(int, int);

int main()
{
    int num1 = 10;
    int num2 = 20;
    int sum;
    sum = add(num1, num2);

    // printf("sum of the numbers: %d", sum);
    cout << "sum  of the numbers is : " << sum << endl;
}

// add function's definition
int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}
