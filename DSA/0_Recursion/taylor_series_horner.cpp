/**
 * Taylor Series using Horner's Rule
 *
 * In the normal taylor series, the number of multiplications are in the order of n^2.
 * But using Horner's Rule, the number of multiplications are reduced to n.
 *
 * Space complexity: O(n) => due to the number of recursive calls and static variable used is 1
 * Time complexity: O(n) => since the number of multiplicaiton reduced to n-1, the recursive calls have been reduced to n
 *
 */

#include <iostream>
using namespace std;

double taylor_series_horner(double x, double n);

int main()
{
    int x, n;
    cout << "Enter the exponent value:" << endl;
    cin >> x;
    cout << "Enter the number of terms:" << endl;
    cin >> n;

    cout << "The evaluated value is: " << taylor_series_horner(x, n) << endl;

    return 0;
}

double taylor_series_horner(double x, double n)
{
    // we ened to track the denominator
    static int denominator = 1;
    int local_denominator = 0;
    if (n == denominator)
    {
        return (double)1 + x / n;
    }
    else
    {
        local_denominator = denominator;
        denominator++;
        return (double)1 + (x / local_denominator) * taylor_series_horner(x, n);
    }
}