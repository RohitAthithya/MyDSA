
// at some point the recursion must terminate

#include <iostream>
using namespace std;

void fun1(int x)
{
    if (x > 0)
    {
        cout << x << endl;
        fun1(x - 1);
        cout << x << endl; // comment and run this line - this is to understand the stack trace in recursion
    }
}

int main()
{
    int x = 3;
    fun1(x);

    return 0;
}

/**
 * Note :
 *
 * When do you prefer recursive implementation over loop based implementation?
 *   - If you need stack records of each iteration to be accessed in near future.
 *   - i.e.The data in each iteration is required after that iteration - then we go for a recursive call.
 */