/**
 * Find the sum of first 'n' natural numbers.
 *
 * Input: 'n' : number of natural numbers to be considered starting from 1
 * Output: sum of the first 'n' natural numbers
 *
 * edge cases:
 * n = 0 : return 0
 * n = 1 : return 1
 * n < 0 : inform user: "bad input, expected a intergeral number >= 1"
 * n != integeral value: "bad input, expected a intergeral number >= 1"
 */

int sumOfN_recursive(int n);
int sumOfN_iterative(int n);
int sumOfN_formula(int n);

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the 'n' to find sum of first 'n' natural numbers" << endl;
    cin >> n;

    // handle -ve test cases here

    // find the sum of 'n' natural numbers
    // int summ = sumOfN_recursive(n);
    // int summ = sumOfN_iterative(n);
    int summ = sumOfN_formula(n);
    cout << "Calculated sum = " << summ << endl;
    return 0;
}

/**
 * recursive approach:
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 *
 * Concept:
 * if n = 7
 * => sum = 1 + 2 + 3 + 4 + 5 + 6 + 7
 * => sum = 1 + 2 + 3 + 4 + 5 + (n-1) + 7
 * => sum = sum(n-1) + n
 *
 */
int sumOfN_recursive(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sumOfN_recursive(n - 1) + n;
    }
}

/**
 * Iterative approach
 * Time complexity: O(n)
 * Space complexity: O(1) //no dynamic memory allocation - just constant space for the 3 variables used
 *
 * concept:
 * with a loop calculate the sum
 */
int sumOfN_iterative(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

/**
 * Formula based approach
 * Time complexity: O(1)
 * Space complexity: O(1)
 *
 * concept:
 * There always a simpler math equation that will get you what you need
 * note that:
 * sum of n natural numbers = n * (n-1)/2
 */
int sumOfN_formula(int n)
{
    return (n * (n - 1) / 2);
}

/**
 * Developer note, it is interesting to see how we optimise the code by improving[reducing] the time and space complexity
 *
 * Teacher note:
 * usually math will solve the problems in a recursive way, we as programmers need to carefully look at the method, and
 * devise the loop based approach inorder to reduce the space complexity, may be even the time complexity
 */