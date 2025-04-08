/**
 * Tower of hanoi:
 * ------------------
 * Given N discs arragned in tower A, decreasing in size from bottom up
 * Move the N discs to tower C with same arrangement as at A
 * Auxillary tower B is available,
 * Larger disc cannot be placed on top of smaller discs when rearranging
 *
 * Note we are going to just print the steps and utilise a browser game to visualise the steps:
 * link: https://www.mathsisfun.com/games/towerofhanoi.html
 * -----------------------
 * this problem is solved using recursion
 * -----------------------
 *
 */

#include <iostream>
using namespace std;

typedef enum TowerName
{
    towerA = (char)'A',
    towerB = (char)'B',
    towerC = (char)'C',
} TowerName;

void tower_of_hanoi(int, char, char, char);
int main()
{
    /*code here*/
    int numOfDiscs;
    cout << "Enter the number of discs for tower of hanoi game" << endl;
    cin >> numOfDiscs;
    cout << "The steps are as follows:" << endl;
    cout << "-------------------------" << endl;
    tower_of_hanoi(numOfDiscs, towerA, towerB, towerC);

    return 0;
}

/**
 * Tower of Hanoi :
 * Print the steps to solve tower of hanoi game for n discs
 *
 * Time complexity:
 * ----------------
 *
 *
 * Space complexity:
 * -----------------
 *
 */
void tower_of_hanoi(int noOfDiscs, char startTwr, char auxTwr, char finalTwr)
{
    static int steps = 1;
    if (noOfDiscs == 1)
    {
        cout << steps << ". Move the disc from tower: " << startTwr << " to tower: " << finalTwr << endl;
        steps++;
    }
    else
    {
        tower_of_hanoi(noOfDiscs - 1, startTwr, finalTwr, auxTwr);
        cout << steps << ". Move the disc from tower: " << (char)startTwr << " to tower: " << (char)finalTwr << endl;
        steps++;
        tower_of_hanoi(noOfDiscs - 1, auxTwr, startTwr, finalTwr);
    }
}