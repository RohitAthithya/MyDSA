/**
 *
 * Find the m raise to power of n
 *
 * Input:
 *  1. 'base' : any integer of floating value
 *  2. 'exponent : the power upto which the base needs to raised to
 * Output: value of m raised to the power of 'n'
 *
 * edge cases:
 * 0^n => 0
 * n^0 => 1
 * 1^n => 1
 * odd powers of -ve number results in -ve value
 * even powers of +ve number, results in +ve value
 *
 *
 */

#include <iostream>
using namespace std;

long double powerOfN_recursive(float base, int exponent);
long double powerOfN_recursive_2(float base, int exponent);
long double powerOfN_iterative(float base, int exponent);

int main()
{
    long double base = 0;
    int64_t exponent = 0;

    cout << "Enter the value of the base [any intergeral/decimal value]" << endl;
    cin >> base;
    cout << "Enter the value of exponent: [the base will be raised to this value]" << endl;
    cin >> exponent;

    if (exponent < 0)
    {
        cout << "Can not calculate -ve exponents" << endl;
        return 1;
    }

    float value = 0;
    // value = powerOfN_recursive(base, exponent);
    value = powerOfN_recursive_2(base, exponent);
    // value = powerOfN_iterative(base, exponent);
    cout << "Calculated power = " << value << endl;

    return 0;
}

/**
 * Recursive approach
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * concept:
 * if base = 3 and exponent = 5
 * => power = 3 * 3 * 3 * 3 * 3
 * => power = (3 * 3 * 3 * 3) * 3
 * => power = power(base, exponent-1) * base
 */
long double powerOfN_recursive(float base, int exponent)
{
    if (base == 0)
        return 0;
    if (base == 1)
        return 1;
    if (exponent == 1)
    {
        return base;
    }
    else
    {
        return (powerOfN_recursive(base, exponent - 1) * base);
    }
}

/**
 * Recursive approach
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * power can be calculated using repetitive multiplication
 * -> if the exponent is even, then the base value is squared and the exponent is halved.
 * -> if odd, then the base value is squared and the exponent is decremented by 1 and halved.
 *
 */
long double powerOfN_recursive_2(float base, int exponent)
{
    if (base == 0)
        return 0;
    if (base == 1)
        return 1;
    if (exponent == 0)
    {
        return 1;
    }
    else if (exponent % 2 == 0)
    {
        return (powerOfN_recursive_2(base * base, (exponent / 2)));
    }
    else
    {
        return (powerOfN_recursive_2(base * base, (exponent - 1) / 2) * base);
    }
}

/**
 * Iterative approach
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * Concept:
 * loop through the exponent and multiply the base value to find the power
 *
 */
long double powerOfN_iterative(float base, int exponent)
{
    long double power = 0;

    if (base == 0)
        return 0;
    if (base == 1)
        return 1;

    for (int i = exponent; i > 0; i--)
    {
        power *= base;
    }
    return power;
}