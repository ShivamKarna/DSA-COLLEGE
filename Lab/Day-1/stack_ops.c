// 13 Jestha, 27 May , Wednesday
/*
  Lab-1 -> Stack and it's Applications
  1. a) Implement stack as an ADT in C.                           
  1. b) Evaluate post fix expression. (C, C++, Python, JavaScript)
*/ 
 // a) Implement stack as an ADT in C.

#include<stdio.h>
#define MAX 5
#define true 1
#define false 0

typedef struct
{
  int data[MAX];
  int top;
}Stack;



int isEmpty(Stack *s){
  s->top == -1  ? true : false;
}


int isFull(Stack *s){
  s->top == MAX-1?true : false;
}

void push( Stack *s,int element){
  if (isFull(s)){
    printf("Stack Overflow\n");

  }else{
    s->data[++(s->top)] = element;
    printf("%d Pushed into stack\n",element);
  }
}

int pop( Stack *s){
  int element;
  if (isEmpty(s)){
    printf("Stack Underflow\n");
  }else{
    element = s->data[(s->top)--];
    printf("%d Popped from stack\n",element);
  }
}

int main(){
  Stack s = {.top=-1};

  int element;
  int choice;

  do{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("2. Exit\n");

    printf("\nEnter Your Choice : ",choice);
    scanf("%d",&choice);

    switch (choice)
    {
      case 1:

      // take input
      printf("Enter element to push into stack : ");
      scanf("%d",&element);

      // push
      push(&s,element);


      break;

      case 2:
      pop(&s);
      break;

      case 3:
      printf("Program Ended ! ! !");
      break;

      default:
      printf("Please choose between 1, 2, and 3 !");
      break;
    }


  } while(choice != 3);

  return 0;
  
}