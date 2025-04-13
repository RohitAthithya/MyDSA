/**
 * Find the value of the taylor series upto n terms
 *
 * the taylor series is a combination of 3 of the series that we had done
 *
 * Input: 'n'
 *
 * recursive approach:
 * time complexity: O(n)
 * space complexity: O(n) - as n stack frames are created
 */

#include <iostream>
using namespace std;

long double taylor_series(int, int);

int main()
{
    int n, x;
    // int n = 4, x = 4;
    cout << "Enter the value of number of terms : ";
    cin >> n;
    cout << "Enter the value of exponent: ";
    cin >> x;

    cout << "The value of the taylor series is: " << taylor_series(n, x) << endl;

    return 0;
}

long double taylor_series(int n, int x)
{
    static long double p = 1; // declaring these two as ints and later typecase them to long double, will cause approximation errors
    static long double f = 1;

    if (n == 0)
        return (long double)1;
    else
    {
        long double local_sum = taylor_series(n - 1, x);
        p = p * x;
        f = f * n;
        return (long double)(local_sum + p / f); // IT IS A MUST TO typecast the division to long double
        // else the result would be in integer!
    }
}