#include "queue.h"

template <class temp>
Queue::Queue()
{
    start = end = size = 0;
    arr = new temp[100];
}

template <class temp>
void Queue::push(temp x) 
{
    arr[end] = x;
    end++;
    size++;
}

template <class temp>
temp Queue::pop()       
{
    if (start == end)
    {
        cout << "Queue is empty" << endl;
        return temp();
    }

    size--;
    return arr[start++];
}

template <class temp>
int Queue::getSize()
{
    return size;
}