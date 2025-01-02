/**
 * TODO: find the perimeter and the area of a rectangle
 *      consider user inputs
 *
 */

#include <stdio.h>

typedef struct Rectangle
{
    int length;
    int breadth;
} Rectangle;

int area(Rectangle tR1)
{
    return tR1.length * tR1.breadth;
}

int perimeter(Rectangle tR1)
{
    return 2 * (tR1.length + tR1.breadth);
}

int main()
{
    Rectangle r1;
    // other wise they result in garbage values, causing condusions especially in large code bases!
    printf("enter the length and breadth, space seperated:\n");
    scanf("%d %d", &r1.length, &r1.breadth);

    int perim = perimeter(r1);
    int ar = area(r1);

    printf("area is %d unit^2, perimeter is %d units", ar, perim);

    return 0;
}