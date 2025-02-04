/**
 * Nested recursion:
 *
 * When the recursive call's parameter is a recursive call.
 * Of course the recursive call must be on the same function to classify it as a nested recursion.alignas
 *
 */

#include <iostream>
using namespace std;

int fun(int n);

int main()
{
    int value = 0;
    value = fun(95);
    cout << value << endl;

    return 0;
}

/**
 * function: fun
 * This is a nested recursive method.
 * Notice the recursive call and the parameter used by the call.
 *
 *
 */
int fun(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return fun(fun(n + 11));
    }
}