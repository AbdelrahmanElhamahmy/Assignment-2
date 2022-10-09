#include "person.h"

class Queue
{
    temp* arr;
    int start, end, size;
public:

    Queue();
    void push(temp x); // push function
    temp pop();       // pop function
    int getSize();
};
