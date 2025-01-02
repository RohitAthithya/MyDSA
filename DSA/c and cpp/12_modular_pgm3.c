/**
 * TODO: find the perimeter and the area of a rectangle
 *      consider user inputs
 *
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct Rectangle
{
    int length;
    int breadth;
} Rectangle;

// initialise a structure Rectangle and return a pointer to it
Rectangle *initialise()
{
    int length = 0, breadth = 0;
    printf("enter the length and breadth, space seperated:\n");
    scanf("%d %d", &length, &breadth);
    Rectangle *pRect = (Rectangle *)malloc(1 * sizeof(Rectangle));
    pRect->length = length;
    pRect->breadth = breadth;
    return pRect;
}

int area(Rectangle *tR1)
{
    return tR1->length * tR1->breadth;
}

int perimeter(Rectangle *tR1)
{
    return 2 * (tR1->length + tR1->breadth);
}

void display(int area, int perimeter)
{
    printf("area is %d unit^2, perimeter is %d units", area, perimeter);
}

int main()
{
    Rectangle *pRect = initialise();
    int ar = area(pRect);
    int perim = perimeter(pRect);
    display(ar, perim);

    return 0;
}

/// the goal in this style of programming is that:
// main know what to do: he diverts all the work to the sub workers like initialise, area and perimeter
// main now just calls this sub workers in the order it wants to perform the actual task

// the next step in code styling is object orientation
