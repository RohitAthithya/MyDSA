/**
 * TODO: find the perimeter and the area of a rectangle
 *      consider user inputs
 *
 */

// this code is to just understand the style of programming only
#include <stdio.h>

int main()
{
    int length = 0, breadth = 0; // initialsing a variable when declaring is better programmin practice
    // other wise they result in garbage values, causing condusions especially in large code bases!
    scanf("%d %d", &length, &breadth);

    int perimeter = 2 * (length + breadth);
    int area = length * breadth;

    printf("area is %d unit^2, perimeter is %d units", area, perimeter);

    return 0;
}