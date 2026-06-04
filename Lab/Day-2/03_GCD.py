#c) GCD using iterationa dn recursion.
# Greatest Common Divisor , we can also say HCF

from timeit import default_timer

def GCD(n1,n2 :int)->int:  
  if n2 == 0:
    return n1
  else: 
    return GCD(n2,n1 % n2)

n1 = int(input("Enter a number n1 less than n2: "))
n2 = int(input("Enter a number greater than n1: "))
start = default_timer()
result = GCD(n1,n2)
end = default_timer()
print(f"The result is {result}")
print(f"Execution Time :{end-start}seconds")

