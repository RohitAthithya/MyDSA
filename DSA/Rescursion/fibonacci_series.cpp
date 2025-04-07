#include <iostream>
#include <algorithm>

using namespace std;

long long int fibonacci_series(int n);
long long int fibonacci_series_memoized(int n, long long int *);
long long int fibonacci_series_memoized_style_2(int n, long long int *);
long long int fibonacci_series_iterative(int);

int main()
{
    int n;
    cout << "Enter 'n' upto which value of fibonacci series needs to found: " << endl;
    cin >> n;
    // n = 5;
    cout << "The value of fibonacci series upto '" << n << "' terms is: " << fibonacci_series(n) << endl;

    // memoized implementation:
    long long int *results = new long long int[n + 1];
    std::fill(results, results + n + 1, (int)-1);
    cout << "The value of MEMOIZED fibonacci series upto '" << n << "' terms is: " << fibonacci_series_memoized(n, results) << endl;

    std::fill(results, results + n + 1, (int)-1);
    cout << "The value of MEMOIZED fibonacci series style 2 upto '" << n << "' terms is: " << fibonacci_series_memoized_style_2(n, results) << endl;
    delete results;

    cout << "The value of ITERATIVE fibonacci series upto '" << n << "' terms is: " << fibonacci_series_iterative(n) << endl;

    return 0;
}

/**
 * Recursive function to find the value of fibonacci series upto nth term
 *
 * Time complexity: O(2^n)
 * ------------------------
 *  note that in each recursive call there is 2 recursive calls
 *  making the time complexity => O(2^n)
 *
 * Space complexity: O(n)
 * ------------------------
 *  note that stack tree goes upto n levels deep
 *  and each function call takes O(1) space
 *  making the total space complexity => O(n)
 *
 */
long long int fibonacci_series(int n)
{
    // recursive solution
    if (n <= 1) // 0 or 1 => return the same, as fib(0) = 0 and fib(1) = 1
        return n;
    else
        return fibonacci_series(n - 1) + fibonacci_series(n - 2);
}

/**
 * Recursive solution with memoization:
 * Note: memoization means: storing the result of function calls that are used multiple times
 * when such calls are made in the future, the stored result is used instead of executing the function again
 *
 * Time complexity: O(n)
 * ------------------------
 * Though there are recursive calls, once a call is made, its result is stored,
 * making future calls on the same number to be O(1) time complexity
 * Thus there is possibility to call only O(n) times.
 * making the total time complexity as O(n)
 *
 * Space complexity: O(n)
 * ------------------------
 * The maximum height of the stack tree is n.
 * Though the results of a function call on a unique number is called only once, it has to be calculated
 * the first time and then stored. [Thus allowing only the future calls to be of O(1) complexity].
 *
 * Therefore the space compelxity of this method is also O(n)
 *
 *
 */
long long int fibonacci_series_memoized(int n, long long int *results)
{
    // static long long int results[1000] = {-1}; //cannot initialise an array with all -1s like this in c++

    if (results[n] >= 0)
        return results[n];

    if (n <= 1)
    {
        results[n] = n;
        return n;
    }
    else
    {
        int fibonacci = 0;
        fibonacci = fibonacci_series_memoized(n - 2, results) + fibonacci_series_memoized(n - 1, results);
        results[n] = fibonacci;
        return fibonacci;
    }
}

/**
 * In this style of fibonacci series, the instructor provided a clean code for better understanding
 * The time and space complexity is same as the other style of recursion
 *
 */
long long int fibonacci_series_memoized_style_2(int n, long long int *results)
{
    if (n <= 1)
    {
        results[n] = (long long int)n;
        return n;
    }
    else
    {
        if (results[n - 2] < 0)
        {
            results[n - 2] = fibonacci_series_memoized_style_2(n - 2, results);
        }
        if (results[n - 1] < 0)
        {
            results[n - 1] = fibonacci_series_memoized_style_2(n - 1, results);
        }
        results[n] = results[n - 2] + results[n - 1];
        return results[n];
    }
}

/**
 * Iterative solution for fibonacci series evaluation
 *
 * Time complexity: O(n)
 * ---------------------
 *  In iterations, the evaluation occurs only n times.
 *  Because the fibonacci of the number is sum of previous two fibonacci numbers
 *  that can be tracked easily in iteration using variables [checkout the implementation]
 *
 * Space complexity: O(1)
 * ----------------------
 *  No additional variables are required as N varies. [no dynmic allocation required]
 *  i.e. only a few variables are required even if n = 5 or 500000
 *
 */
long long int fibonacci_series_iterative(int n)
{
    if (n <= 1)
        return n;

    long long int n_2 = 0;
    long long int n_1 = 1;
    long long int result = 0;

    for (long long int iter = 2; iter <= n; ++iter)
    {
        result = n_2 + n_1;
        n_2 = n_1;
        n_1 = result;
    }
    return result;
}