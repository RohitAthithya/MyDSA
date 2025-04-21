/**
 * Array:
 * -------
 * Static and dynamic memory allocation
 *  - understand the differences
 *  - understand the stack and heap segments
 *  - understand the memory allocation functions
 *  - understand the free and delete function
 *  - understand the use of pointers
 *
 * Memory:
 * --------
 * Note that when every program is executed, there are a lot of processes that occur and result in the .exe file
 * or the executable file
 *
 * When this executable is loaded in to the memory, the memory is divided into multiple segments, viz:
 * 1. Text or code segment: [also RO segment => read only]
 *      - the code written is converted to machine code based instructions and are stored here
 *      - when executable is loaded, the instructions are executed with info from this segment
 * 2. Data segment: [also RW segment => read write]
 *     - this segment stores the global and static variables of the program
 *     - note that all the information from the program is read at the compile time and the data segment is created
 *     - This segment is divided into two parts:
 *     2.1. Initialized data segment:
 *          this segment stores the initialized global and static variables
 *        - Further divided into two parts:
 *           2.1.1. Read only data segment: [RO - DS]
 *              - this segment stores the read only variables: as in:
 *              -  the string literals
 *              -  the const variables
 *           2.1.2. Read write data segment: [RW - DS]
 *              - this segment stores the read write variables viz.:
 *              - initialized global and static variables
 *     2.2. Uninitialized data segment: [also BSS segment => block started by symbol]
 *       - this segment stores the uninitialized global and static variables
 * 3. stack/heap segment are both in the same space, stack grows downwards and heap grows upwards
 *      3.1. Stack segment: [also LIFO segment => last in first out]
 *          - stores local variables
 *          - created when the function is called and destroyed when the function returns
 *          - this segment is used for static memory allocation: i.e., the size of memory to be allocated
 *           is known at compile time but actual memory is allocated at runtime
 *          - stack records are what make recursion useful in one aspect, all the function calls have a stack
 *           record or stack frame that stores the function call information
 *          !NOTE:
 *         - stack segment is faster than heap segment
 *         - stack segment is limited in size, i.e., the maximum size of the stack segment is limited
 *      3.2 Heap segment: [also FIFO segment => first in first out]
 *         - stores dynamic variables: i.e. variables whose size is not known at compile time
 *         - program instruction must mention the size of memory to be allocated at runtime
 *         - this segment can be accessed only by using pointers, normal variables do not point to this segment,
 *              rather they point to the stack segment [variable are stored in stack only]
 *         - Once initialised, it is not freed/destroyed until:
 *              a. exclusivly/intentionally freed/destroyed by the program using the free() or delete keyword
 *              b. the program ends
 *         - When memory is allocated to heap segment, usually a pointer to its starting address is returned
 *             by the new keyword or malloc function
 *         - if the variable holding this pointer information is reassigned or "forgotten", it does not destroy
 *              the allocated heap segment, i.e. this memory cannot be reallocated to further allocation requests
 *              the further allocation requests have to be made in the remaining space, since there were no requests
 *              to deallocated this memory or tell that "hey, this memory is no longer needed, you can use it for
 *              further allocation requests"
 *          - this is called memory leak, i.e. the memory is allocated but not freed and the further allocation
 *              requests take place in the remaining segments; gradually,
 *              heap segment will run out of memory, and the program will crash / go gives unknown behavior
 *
 */

#include <iostream>
using namespace std;

int main()
{
    // declaration and initialization of array: this array occupies space in the stack segment
    int arr[5] = {2, 4, 6, 8, 10};

    cout << "contents of arr :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "value at " << i << " :" << arr[i] << endl;
    }

    int *pArr;
    pArr = (int *)malloc(5 * sizeof(*pArr)); // malloc allocates the given amount of memory size in heap segment
    // pArr = new int[5]; // this is also a way to allocate memory in the heap segment

    *(pArr + 0) = 1;
    pArr[1] = 3;
    pArr[2] = 5;
    pArr[3] = 7;
    4 [pArr] = 9;

    cout << endl
         << "contents of pArr in the heap segment: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "value at " << i << " :" << pArr[i] << endl;
    }

    // free(pArr); //this is used in c to free the memory allocated in the heap segment
    delete[] pArr; // free the memory allocated in the heap segment by the malloc function or the new keyword
    return 0;
}