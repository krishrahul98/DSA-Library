/*  

Author: Shail Shah
Github: /shailshah76

*/

#include "Queue_Implementation.cpp"
#include <iostream>

int main(){
    Queue<int> arr(5);
    arr.Enqueue(1);
    arr.Enqueue(2);
    arr.Enqueue(3);
    arr.Enqueue(4);
    std::cout<<"Queue Size is: "<<arr.size()<<std::endl;
    std::cout<<"Front is: "<<arr.Front()<<std::endl;
    std::cout<<"Rear is: "<<arr.Rear()<<std::endl;
    arr.Dequeue();
    arr.Dequeue();
    std::cout<<"Queue Size is: "<<arr.size()<<std::endl;
    std::cout<<"Front is: "<<arr.Front()<<std::endl;
    std::cout<<"Rear is: "<<arr.Rear()<<std::endl;
    return 0;
}


/*

To compile the code:

g++ -o main.cpp Queue_Implementation.cpp 

This will generate main.o object file

Then run the file

./main

*/