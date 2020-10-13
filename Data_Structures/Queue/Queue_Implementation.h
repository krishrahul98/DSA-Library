/*

Author: Shail Shah
Github: /shailshah76


*/
#pragma once

template <typename T>
class Queue{

    T* queue;
    int front,rear;
    int curr_size;
    int capacity;

    public:
        Queue(int s);
        void Enqueue(T val);                                //pushes element in the queue
        void Dequeue();                                     //removes  element from the queue
        T Front();                                          //returns front of the queue
        T Rear();                                           //returns rear of the queue
        int size();
};