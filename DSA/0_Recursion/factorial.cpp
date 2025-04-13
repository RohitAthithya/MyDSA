#include "factorial.hpp"
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
