

#include <iostream>
using namespace std;

// all the data and the data related functionality is represented within a class
// by default members of a struct in C++ are public
// by default members of a class in C++ are private

class Rectangle
{
private:
    int length;
    int breadth;
    // int length = 0; // after c++11, the non-static variable  initialisation of the class/structs is allowed
    // int breadth = 1;

public:
    // void initialise(int l, int b)
    // {
    //     length = 0;
    //     breadth = 0;
    //     printf("enter the length and breadth, space seperated:\n");
    //     scanf("%d %d", &length, &breadth);
    //     length = length;
    //     breadth = breadth;
    // }

    // such an initialiser is not required, instead, we use the constructors -> more intuitive
    Rectangle();

    // and then a bunch of getters and setters
    int getLength() const
    {
        return length;
    }

    void setLength(int value)
    {
        length = value;
    }

    int getBreadth() const
    {
        return breadth;
    }

    void setBreadth(int value)
    {
        breadth = value;
    }

    // special methods
    int area();
    int perimeter();
    void d();

    ~Rectangle();
};

int main()
{
    // Rectangle r;
    // r.initialise()
    Rectangle r;
    // int ar = r.area();
    // int perim = r.perimeter();
    r.displayAreaAndPerimeter();
    // r.setLength(99);
    // r.getLength();
    return 0;
}

Rectangle ::Rectangle() : length(0), breadth(0)
{
    // length = 0;
    // breadth = 0;
    printf("enter the length and breadth, space seperated:\n");
    scanf("%d %d", &length, &breadth);
    length = length;
    breadth = breadth;
}

int Rectangle ::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

void Rectangle::displayAreaAndPerimeter()
{
    printf("area is %d unit^2, perimeter is %d units", this->area(), this->perimeter());
}

Rectangle ::~Rectangle()
{
    // do nothing
}