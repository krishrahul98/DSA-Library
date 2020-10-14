/*

Author: Shail Shah
Github: /shailshah76


*/

#include "Queue_Implementation.h"
#include <iostream>

template <typename T> Queue<T>::Queue(int s){
    queue = new T[s];
    front = 0;
    rear = -1;
    curr_size = 0;
    capacity = s;
}

template <typename T> void Queue<T>::Enqueue(T val){
    if(this->size() == capacity){
        std::cout<<"OverFlow";
    }
    rear = (rear + 1) % capacity ;
    curr_size++;
    queue[rear] = val;
}

template <typename T> void Queue<T>::Dequeue(){
    if(this->curr_size == 0){
        std::cout<<"UnderFlow";
    }
    front = (front + 1) % capacity;
    curr_size--;
}

template <typename T> T Queue<T>::Front(){
    return queue[front];
}

template <typename T> T Queue<T>::Rear(){
    return queue[rear];
}

template <typename T> int Queue<T>::size(){
    return curr_size;
}