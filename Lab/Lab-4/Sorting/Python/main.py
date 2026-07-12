import time
import random


# linking the files via imports
from bubble_sort import bubble_sort
from selection_sort import selection_sort
from insertion_sort import insertion_sort

def generate_random_elements(n: int) -> list[int]:
    return [random.randint(0, 1000000) for _ in range(n)]

def print_array(arr: list[int])->None: 
    print(*(arr))

def main():
    try:
        n =int(input("Enter n : "))
    except ValueError:
        print("Invalid Size : ")
        return
    
    arr = generate_random_elements(n)

    print("Sorting...")

    start = time.perf_counter()
    
    # selection_sort(arr) 
    insertion_sort(arr)
    
    end = time.perf_counter()

    print_array(arr) 
    
    time_taken = end - start
    print(f"Time taken is {time_taken:.8f} s")

if __name__ == "__main__":
    main()