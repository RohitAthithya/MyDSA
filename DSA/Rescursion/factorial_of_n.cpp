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

#include <iostream>
using namespace std;

uint64_t factorial_recursive(int n);
uint64_t factorial_iterative(int n);

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

/**
 * Recursive approach
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 *
 * concept:
 * if n = 7
 * => factorial(n) = 1 * 2 * 3 * 4 * ... * 6 * 7
 * => factorial(n) = 1 * 2 * 3 * 4 * ... * (7-1) * 7
 * => factorial(n) = factorial(n-1) * n
 */
uint64_t factorial_recursive(int n)
{
    if ((n == 0) || (n == 1))
        return 1;
    else
        return factorial_recursive(n - 1) * n;
}

/**
 * Iterative approach
 *
 * Time complexity: O(n)
 * Space complexity: O(1) => constant space
 *
 *
 * concept:
 * using a for loop calculate the product of the first n nos. from 1
 */
uint64_t factorial_iterative(int n)
{
    if ((n == 0) || (n == 1))
        return 1;

    uint64_t sum = 1; // possible error - to initialize this with 0!

    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
