
// Templates: use same class for multiple data types
// need not write seperate classes for every dataa type
// for e.g. the class Arithmetic, working on just 2 variables and having add and sub methods: need not be written for int and float seperately!
// make it a template, and start using it with any datatypes that you want

#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>
class Arithmetic
{
private:
    T num1;
    T num2;

public:
    Arithmetic(T num1, T num2);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T num1, T num2)
{
    this->num1 = num1;
    this->num2 = num2;
}

template <class T>
T Arithmetic<T>::add()
{
    return (num1 + num2);
}

template <class T>
T Arithmetic<T>::sub()
{
    return (num1 - num2);
}

int main()
{
    Arithmetic<int> op1(4, 10);
    Arithmetic<float> op2(20.5, -10.0);

    cout << "added values of op1 :" << op1.add() << " and op2 : " << op2.add() << endl;
    cout << "type of return from add of op1 :" << typeid(op1.add()).name() << " and op2 : " << typeid(op2.add()).name() << endl;

    cout << "sub values of op1 :" << op1.sub() << " and op2 : " << op2.sub() << endl;
    cout << "type of return from add of op1 :" << typeid(op1.sub()).name() << " and op2 : " << typeid(op2.sub()).name() << endl;
    return 0;
}
