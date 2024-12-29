
// feature only in cpp
// reference is a alias given to a variable!
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a = 10; // in the stack
    int &r = a; // references must be initialised when declared!
    // note: once initialised, references CAN NOT be re-referenced to another variable

    // address of the both the identifiers is the same

    cout << a << endl;
    cout << r << endl;

    r++;

    cout << r << endl;
    cout << a << endl;

    // note that both are the names of the same address: cout ing the address of both
    cout << &r << endl;
    cout << &a << endl;

    r = 25;
    cout << r << endl;

    int b = 100;
    r = b; // note that this does not mean that r is referenced to b : but value of b is stored to r;

    cout << r << endl;

    r = 99;
    cout << r << endl;
    cout << b << endl; // note that this value is still 100, did not change after changing r

    return 0;
}
