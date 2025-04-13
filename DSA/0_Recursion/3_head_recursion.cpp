/**
 * Head recursion:
 * The first [functional] ]instruction of a function is the recursive call
 *
 */

#include <iostream>
using namespace std;

void fun(int);
void fun_loop(int);

int main()
{
    fun(3);
    // fun_loop(3);
    return 0;
}

// Head recursive function
// time - O(n)
// space - O(n)
void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1); // at n = 1, one more call with n = 0 => total of n+1 calls
        cout << "value of n = " << n << endl;
    }
}

// Loop based implmentatin of the above Head recursive function
// Such loop based conversion may prove difficult
// time - O(n)
// space - O(1)
void fun_loop(int n)
{
    int i = 0; // since the recursion will branch until n is not 0 => n+1 calls are done
    while (i++ < n)
    {
        cout << "value of n = " << n << endl;
    }
}

// example of NOT Head recursion
void fun_not_head_recur(int n)
{
    if (n > 0)
    {
        n--;
        fun(n); // at n = 1, one more call with n = 0 => total of n+1 calls
        cout << "value of n = " << n << endl;
    }
}

/**
 * Note that converting head recursion to the looping implementation is possible but can not be done easily!
 *
 * since the 1st instruction is the recursive call, tracing till the condition where recursion stops may prove to be difficult
 */