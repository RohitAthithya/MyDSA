// #include <iostream>
#include "factorial.hpp"
using namespace std;

double combinations(int, int);
double combinations_recursive(int, int);

int main()
{
    int n;
    int r;

    cout << "Enter total number of objects: n: " << endl;
    cin >> n;
    cout << "Enter the number of objects selected at a time: r:" << endl;
    cin >> r;

    cout << "The possbile combinations are :" << combinations(n, r) << endl;
    cout << "The possbile combinations are :" << combinations_recursive(n, r) << endl;

    return 0;
}

/**
 * Combinations:
 * --------------
 * - The Comination is the selection of combinations of r objects at a time out of n objects.
 * - 5C2 means: possible combinations of selecting 2 objects at a time out of 5 objects.
 * - Formula = factorial(n) / (factorial(r) * factorial(n-r))
 *
 * Time complexity: O(n)
 * ---------------------
 * each call to the factorial function is O(n)
 * total of 3 calls => O(3n) => O(n)
 *
 * Space complexity: O(1)
 * ----------------------
 * no additional variable required as n changes, constantly a few are required
 *
 */
double combinations(int n, int r)
{
    double t1 = 0;
    double t2 = 0;
    double t3 = 0;

    t1 = (double)factorial_iterative(n);
    t2 = (double)factorial_iterative(r);
    t3 = (double)factorial_iterative(n - r);

    return t1 / (t2 * t3);
}

double combinations_recursive(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return (combinations_recursive(n - 1, r - 1) + combinations_recursive(n - 1, r));
    }
    return (double)0;
}