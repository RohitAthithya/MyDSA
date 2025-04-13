/**
 * Find the Factorial of number 'n'
 *
 * factorial is defined as :
 * f = 1 * 2 * 3 * 4 * ... * (n-1) * n
 *
 * Input : 'n' : natural no.
 * Output: factorial of the given number 'n'
 *
 *
 * edge cases:
 * n = 0 : return 1
 * n = 1 : return 1
 *
 * n <= 0 : inform user: "bad input, expected a intergeral number >= 1"
 */

#include "factorial.hpp"

using namespace std;

int main()
{
    int n = 0;

    cout << "Enter the 'n' to find it's factorial" << endl;
    cin >> n;

    uint64_t value = 1;
    value = factorial_recursive(n);
    // value = factorial_iterative(n);

    cout << "Calculated factorial = " << value << endl;
    return 0;
}
