/**
 * Tree Recursion:
 * There are more than one compulsory recursive calls in the function.
 *
 */

#include <iostream>
using namespace std;

void fun(int);
void fun_loop(int);
uintmax_t fun_accumulator(int);

int main()
{
    // fun(3);
    fun_accumulator(3);
    return 0;
}

// Example of tree recursion
// In this example, the time and space complexity are as shown
// time - O(2^n)
// space - O(n) [usually depends on the height of tree - at a time how many stack frames exist]
void fun(int n)
{
    if (n > 0)
    {
        cout << "value of n = " << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}
