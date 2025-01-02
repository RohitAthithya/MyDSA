/**
 * TODO: find the perimeter and the area of a rectangle
 *      consider user inputs
 *
 */

#include <stdio.h>

// making changes or adding functionality becomes too much of a head ache - so make the code modular

int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    return 2 * (length + breadth);
}

int main()
{
    int length = 0, breadth = 0; // initialsing a variable when declaring is better programmin practice
    // other wise they result in garbage values, causing condusions especially in large code bases!
    printf("enter the length and breadth, space seperated:\n");
    scanf("%d %d", &length, &breadth);

    int perim = perimeter(length, breadth);
    int ar = area(length, breadth);

    printf("area is %d unit^2, perimeter is %d units", ar, perim);

    return 0;
}