#include<iostream>
#include<string>
#include<vector>
#include<cmath>



std::vector<std::string>splitString(std::string inputString){
  std::vector<std::string> arr; // array to store the string
  std::string tempWord = ""; // to hold the string(number) for each input

  for(int i = 0; i  < inputString.length(); i ++){
    if(inputString[i] == ' '){
      if(!tempWord.empty()){
        arr.push_back(tempWord);
        tempWord = "";
      }
    }
    else{
      tempWord += inputString[i]; 
    }
  }
  if(!tempWord.empty()){
    arr.push_back(tempWord);
  }
  return arr;
}


bool isFloat(std::string inputString){
  if(inputString.empty()) return false;

  bool hasDecimal = false;

  for(int i =0 ; i < inputString.length() ; i++){
    if(inputString[i] == '.'){
      if(hasDecimal == true){
        return false;
      }
      hasDecimal = true; // now that we have seen the . so it's now decimal
    }
    else if(inputString[i]< '0' || inputString[i] > '9'){
      return false;
    }
  }
  return true; 
}


void evalPostfix(){
   std::string postfix;
   std::vector<double> stack;

   std::cout<<"Enter postfix expression : ";
   std::getline(std::cin,postfix);

   std::vector<std::string> symbols = splitString(postfix);

   for (std::string s : symbols){
    if(isFloat(s)){
      stack.push_back(std::stod(s));
    }
   else{
    double firstNum = stack.back();
    stack.pop_back();

    double secondNum = stack.back();
    stack.pop_back();

    double result = 0.0;

    if(s == "+"){
      result =secondNum + firstNum;
      stack.push_back(result);
    }
    else if(s =="-"){
      result =secondNum - firstNum;
      stack.push_back(result);
    }
    else if(s =="*"){
      result =secondNum * firstNum;
      stack.push_back(result);
    }
    else if(s =="/"){
      result =secondNum / firstNum;
      stack.push_back(result);
    }
    else if(s =="^"){
      result =pow(secondNum,firstNum);
      stack.push_back(result);
    }
   }
  }
  std::cout << "The final result is  : " << stack[0] << std::endl;
}


int main() {
    evalPostfix();
    return 0;
}