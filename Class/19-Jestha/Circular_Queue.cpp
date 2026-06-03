
// Circular QUEUE
// Queue as ADT in C++.

/*
The fundamental problem with a linear queue implemented using a fixed-size array is the "false full" condition, 
which leads to a severe waste of memory. As elements are added and removed, both the rear and front pointers advance 
forward in a straight line. Once the rear pointer reaches the very last index of the array, the queue declares itself 
completely full and refuses to accept any new data—even if the entire front of the queue has been 
emptied out via previous removals.

A circular queue solves this limitation by mathematically bending the linear array into a continuous loop using the 
  modulo operator (%). Instead of letting the pointers march off the edge of the array into a dead end, a 
  
  circular queue forces the rear pointer to wrap gracefully back around to index 0 once it hits the boundary. 
  As long as the front pointer has advanced and vacated those early slots, the queue can continuously reuse the empty
 space. This clever wrap-around design ensures that every single slot in the allocated memory can be recycled 
 indefinitely, allowing the queue to handle an infinite stream of data without ever needing to resize or 
 prematurely lock up.

*/

#include<iostream>

const int MAX = 5;
const int TOTAL_SIZE = 6;

struct MyQueue{
  int front= 0;
  int rear = 0;
  //  we can also use count to track full and empty
  int data[TOTAL_SIZE];
};

bool isEmpty(const MyQueue& que){
  return que.rear == que.front;
}

bool isFull(const MyQueue& que){
  return (que.rear + 1) %  TOTAL_SIZE == que.front;
}


void Enqueue(MyQueue& que,int element){
  if(isFull(que)){
    std::cout<<"Queue is Full"<<std::endl;
  }
  else{
    que.data[que.rear] = element;
    que.rear = (que.rear + 1 ) % TOTAL_SIZE;
  }
}

int Dequeue(MyQueue& que){
  if(isEmpty(que)){
    std::cout<<"Queue is Empty !"<<std::endl;
    return -1;
  }
  else{
    int element = que.data[que.front];
    que.front = (que.front + 1) % TOTAL_SIZE;
    return element;
  }
}

int main(){

  struct MyQueue que = {0,0,0};

  Enqueue(que, 11);
  Enqueue(que, 22);
  Enqueue(que, 33);
  Enqueue(que, 44);
  Enqueue(que, 55);
  Enqueue(que, 55);



  return 0;
}
