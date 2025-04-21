/**
 * C/cpp can support multidimensional arrays, as it is our creativity
 * Here, 2D array is discussed due to its applications like matrices, tables, etc.,.
 *
 * There are 3 methods to declare the 2D array
 * 1. int A[3][4];  this creates a tabular data of 3 rows and 4 columns [row and column are for human visualisation ]
 *      this can be initialized as:
 *      int A[3][4] = { {1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12, 13}};
 *      Notice the inner curly braces
 * also: this array is also in the stack frame of main method - thus a static array
 *
 * 2. int *A[3];
 *    A[0] = new int[4]
 *    A[1] = new int[4]
 *    A[2] = new int[4]
 *
 *      we have an array of pointers where each pointer points to an array
 *      This method gives us the same power of 2D array
 *
 * 3. int **A;
 *    A[0] = new int*[4]
 *    A[1] = new int*[4]
 *    A[2] = new int*[4]
 *
 */

#include <stdio.h>
#include <stdlib.h>

// using namespace std;

void print2DArray(int **arr, int rows, int cols);
void initArray(int **arr, int rows, int cols);

int main()
{
    // 1. 2D using normal method
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // print2DArray(A, 3, 4);
    for (int row = 0; row < 3; row++)
    {
        printf(" -----------------------\n");
        printf(" | ");
        for (int col = 0; col < 4; col++)
        {
            // printf("%d | ", A[row][col]);
            printf("%d | ", *(*(A + row) + col));
            // printf("%d | ", *(*(A + col) + row));
        }
        printf("\n -----------------------");
    }

    printf("\n\n");
    // 2.
    int *B[3];
    B[0] = (int *)malloc(4 * sizeof *B);
    B[1] = (int *)malloc(4 * sizeof *B);
    B[2] = (int *)malloc(4 * sizeof *B);

    initArray(B, 3, 4);
    print2DArray(B, 3, 4);
    printf("\n\n");

    // 3. using double pointers
    int **C;
    C = (int **)malloc(3 * sizeof(*C));
    for (int temp = 0; temp < 3; temp++)
    {
        C[temp] = (int *)malloc(4 * sizeof(*C));
    }

    initArray(C, 3, 4);
    print2DArray(C, 3, 4);
    printf("\n\n");
    return 0;
}

void print2DArray(int **arr, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        printf(" -----------------------\n");
        printf(" | ");
        for (int col = 0; col < cols; col++)
        {
            printf("%d | ", arr[row][col]);
        }
        printf("\n -----------------------");
    }
}

void initArray(int **arr, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            arr[row][col] = (row * cols) + col;
        }
    }
}