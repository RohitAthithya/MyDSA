/**
 * Tail recursion:
 * Recursion where the recursive call is the last executable statement in the functions
 * i.e. there must be no pending instructions when the recursive calls backtrack their previous calls.
 *
 * Of course, this type of recursion can be easily converted to a loop based implementation
 */

#include <iostream>
using namespace std;

// tail recursive function
void fun1(int);
void fun1_loop(int);
int fun2(int);

int main()
{

    // fun1(3);
    fun1_loop(3);
    // fun2(15);
    return 0;
}

// time - O(n)
// space - O(n)
void fun1(int n)
{
    cout << "lets look at tail recursion" << endl;
    if (n > 0)
    {
        cout << "n = " << n << endl;
        fun1(n - 1);
    }
}

// time - O(n)
// space - O(1)
void fun1_loop(int n)
{
    cout << "lets look at tail recursion with looping approach" << endl;
    while (n > 0)
    {
        cout << "n = " << n << endl;
        n--;
    }
}

// examples of NOT: tail recursions
int fun2(int n)
{
    static int accumulator = 0;
    if (n > 0)
    {
        int ret;
        --n;
        ret = fun2(n) + n; // doing something after the recursive call
        accumulator += ret;
        cout << "accumulated value = " << accumulator << endl;
    }
    return n;
}

/**
 * Note some compilers may optimise tail recursion into corr. looping method
 */