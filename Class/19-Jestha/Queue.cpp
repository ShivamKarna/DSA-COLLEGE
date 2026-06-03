// Linear QUEUE
// Queue as ADT in C++.

#include<iostream>

#define MAX 5

struct MyQueue{
  int front= 0;
  int rear= -1; // just for the sake it's linear queue putting rear -1
  int data[MAX];
  int count = 0;
};


bool isFull(const MyQueue& que){
  return que.count == MAX;
}

bool isEmpty(const MyQueue& que){
  return que.count == 0;
}

void Enqueue(MyQueue& que,int element){
  if(isFull(que)){
    std::cout<<"Queue is Full"<<std::endl;
  }
  else{
    que.data[++que.rear] = element;
    que.count++;
  }
}

int Dequeue(MyQueue& que){
  if(isEmpty(que)){
    std::cout<<"Queue is Empty !"<<std::endl;
    return -1;
  }
  else{
    int element = que.data[que.front];
    que.front++;
    que.count--;
    return element;
  }
}
