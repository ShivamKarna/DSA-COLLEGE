# 20 Jestha, Wednesday
"""
 a) Factorial Using recursion and Recursion.
 b) nth Finonacci using Recursion and Memoization.
 c) GCD using iterationa dn recursion.
 d) TOH using Recursion.
"""
from timeit import default_timer

def tailFact(n:int,a:int)->int: 
  if n ==0 or n == 1:  
    return a

  else: 
    return tailFact(n-1,a*n)


n = int(input("Enter a number: "))
start = default_timer()
result = tailFact(n,1)
end = default_timer()
print(f"The result is {result}")
print(f"Execution Time :{end-start}seconds")
