
#13 Jestha, 27 May , Wednesday

"""
  Lab-1 -> Stack and it's Applications
  1. a) Implement stack as an ADT in C.                           
  1. b) Evaluate post fix expression. (C, C++, Python, JavaScript)

 //  b) Evaluate post fix expression. (C, C++, Python, JavaScript)
"""

postfix = input("Enter postfix expression : ")
symbols = postfix.split()
stack = []
for s in symbols:
    try:
        stack.append(float(s))
    except ValueError:
        firstNum = stack.pop()
        secondNum = stack.pop()

        if s == "+":
            stack.append(secondNum + firstNum)
        elif s == "-":
            stack.append(secondNum - firstNum)
        elif s == "*":
            stack.append(secondNum * firstNum)
        elif s == "/":
            stack.append(secondNum / firstNum)
        elif s == "^":
            stack.append(secondNum ** firstNum)

print("The final result is  : ", stack[0])