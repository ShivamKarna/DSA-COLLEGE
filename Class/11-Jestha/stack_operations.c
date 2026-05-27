// Basic Stack Operations

// This was the first day of DSA Class (Of Mine), 
// Today was the first day of PSEUDO Coding and actual Coding


#include <stdio.h>
#define MAX 5
#define true 1
#define false 0

typedef struct{
    int TOP;
    int data[MAX];
} Stack;

int isFull(Stack *S){
    if(S->TOP == MAX-1){
      return true;
    }
    else {
      return false;
    }
  }
int isEmpty(Stack *S){
    if(S->TOP == -1){
      return true;
    }
    else {
      return false;
    }
  }

void push(Stack *S, int element){
    if(isFull(S)){
      printf("Stack Overflow\n");
    }
    else {
      S->data[++(S->TOP)] = element;
      printf("%d was Pushed to stack\n",element);
    }
  }

void pop(Stack *S){
  int element;
  if(isEmpty(S)){
    printf(
      "Stack Underflow\n"
    );
  }
    else {
      element = S->data[(S->TOP)--];
      printf("%d was Popped from stack\n",element);
    }
  }
  
int main(){

  Stack S = {.TOP = -1};// This is equivalent of doing :  // Stack S; S.TOP = -1;

  char choice; 
  int element;


  do{
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. EXIT\n");

    printf("Enter Your Choice : ");
    scanf(" %c",&choice);

    switch (choice)
    {
    case  '1':
      printf("\nEnter an element to Push: ");
      scanf("%d",&element);

      push(&S,element);
      break;

    case '2' : 
      pop(&S);
      break;
    case '3' : 
      printf("Program Ended\n");
      break;
    
    default:
    printf(
      "\nPlease choose between 1, 2 or 3 !\n"

    );
      break;
    }
  }while(choice != '3');

  return 0;


}