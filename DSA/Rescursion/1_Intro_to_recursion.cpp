// explore recursion and storage class specifiers in c
//  at some point the recursion must terminate

#include <iostream>
using namespace std;

void fun1(int x)
{

    if (x > 0)
    {
        cout << x << endl;
        fun1(x - 1);
        // fun1(--x);
        cout << x << endl; // comment and run this line - this is to understand the stack trace in recursion
    }
}

int x = 4;
int main()
{
    // int x = 3;
    extern int x;
    // static int x = 3;
    // x = 3;
    fun1(x);

    return 0;
}

/**
 * Note :
 *
 * When do you prefer recursive implementation over loop based implementation?
 *   - If you need stack records of each iteration to be accessed in near future
 *   - i.e.The data in each iteration is required after that iteration - then we go for a recursive call.
 *
 * Note that a loop will have only an ascending phase
 * but the recursion - due to stack records - have a descending phase
 * i.e. recursive calls can do something after the recursion backtracks [when condition is met, recursive calls stop, the stack trace is back tracked to original point]
 *
 *
 */

int accumulate(unsigned int x)
{

    /* ERROR x is not a compile-time constant. */
    // static unsigned int acc = x;

    static unsigned int acc = 0; /* OK */
    // note: acc is initialised only once when the file is compiled - not during first nor during every call to the function.
    // One copy of this variable is available in the memory segment BSS
    acc = acc + x;
    return acc;
}

// q.: I have a function that does, say, glow an LED. I want to capture the times the this function was callled/ LED was glown.
// use a static variable and return that data to the caller, when this returned data is printed, up-to-date count is known.
