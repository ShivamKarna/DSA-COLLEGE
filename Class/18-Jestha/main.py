def evaluate(postfix: str) -> float:
    stack = [] 
    operators = ('+', '-', '/', '*', '^', '%')

    for token in postfix.split(): 
        if token in operators: 
            val1 = stack.pop()
            val2 = stack.pop()
            
            if token == '+': 
                result = val2 + val1
            elif token == '-': 
                result = val2 - val1
            elif token == '*': 
                result = val2 * val1
            elif token == '/': 
                result = val2 / val1  
            elif token == '%': 
                result = val2 % val1
            elif token == '^': 
                result = val2 ** val1
                
            stack.append(result)
            
        else:
            stack.append(float(token))

    return stack.pop()

print(evaluate("5.5 2.5 +"))