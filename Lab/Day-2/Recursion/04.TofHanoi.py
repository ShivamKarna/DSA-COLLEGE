# d) TOH using Recursion.
from timeit import default_timer

def TOH(n:int=3, src:str ='A', temp:str='B', dest:str='C' )->int:  
  if n == 1:  
    print(f"Move disk {n} from {src} to {dest}")
  else:
    TOH(n-1,src,temp,dest)
    print(f"Move disk {n} from {src} to {temp}")
    TOH(n-1,src,dest,temp)



start = default_timer()
n = int(input("Enter number of iterations : "))
TOH(n)
end = default_timer()
print(f"Total Moves for {n} disks are : {2**n -1}")
print(f"Execution Time :{end-start}seconds")
