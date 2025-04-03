

#include <iostream>
using namespace std;

double taylor_series_iterative(int exponent, int num_of_terms);

int main()
{
    int x, n;
    cout << "Calculating the value of power of natural log 'e' with taylor series" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter the value of exponent: " << endl;
    cin >> x;
    cout << "Enter the value of n (number of terms upto which the taylor series can be expanded): " << endl;
    cin >> n;
    cout << "The value of e^" << x << " is: " << taylor_series_iterative(x, n) << endl;
    return 0;
}

double taylor_series_iterative(int exponent, int num_of_terms)
{

    double result = 1.0;
    double numerator = 1.0;
    double denominator = 1.0;

    if (exponent == 0)
    {
        return (double)1.0;
    }

    for (int i = 1; i <= num_of_terms; ++i)
    {
        numerator *= exponent;
        denominator *= i;
        result += numerator / denominator;
    }

    return result;
}