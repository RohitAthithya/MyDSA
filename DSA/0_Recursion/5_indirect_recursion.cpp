/** Indirect recursion:
 * There may be more than one function,
 * where two or more functions call each other in a cyclic fashion
 *
 * Of course there must be conditions where there must be stop to this cyclic recursion,
 * as in any normal recursion.
 *
 * e.g.:
 * - calculating Riemann sum,
 * - many such algorithms in numerical methods of approximation
 *
 */

#include <iostream>
using namespace std;

void funA(int n);
void funB(int n);

int main()
{
    funA(5);

    return 0;
}
void funA(int n)
{
    if (n > 0)
    {
        cout << "A >> " << n << endl;
        funB(n - 1);
        cout << "Rvs: A >>" << n << endl;
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << "B >> " << n << endl;
        funA(n - 1);
        cout << "Rvs: B >>" << n << endl;
    }
}