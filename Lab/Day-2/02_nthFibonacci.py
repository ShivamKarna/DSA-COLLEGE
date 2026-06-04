 
# b) nth Finonacci using Recursion and Memoization.

from timeit import default_timer

table = {}
def nFibo(n :int)-> int : 
  if n == 0 or n == 1:
    return n  
  else:
    if n not in table:
      result1=  nFibo(n-1) 
      table[n-1] = result1
      result2 = nFibo(n-2)  
      table[n-2] = result2
      return result1 + result2

    else:
        return table[n]

n = int(input("Enter nth term to be found : "))
start = default_timer()
result = nFibo(n)
end = default_timer()
print(f"The result is {result}")
print(f"Execution Time :{end-start}.2f seconds")

