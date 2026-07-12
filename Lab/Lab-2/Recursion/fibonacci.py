# nth Fibonacci without Tail Recursion Optimization
from timeit import default_timer

def nFibo(n :int)-> int : 
  if n == 0 or n == 1:
    return n  
  else:
    return nFibo(n-1) + nFibo(n-2)


n = int(input("Enter nth term to be found : "))
start = default_timer()
result = nFibo(n)
end = default_timer()
print(f"The result is {result}")
print(f"Execution Time :{end-start}seconds")

