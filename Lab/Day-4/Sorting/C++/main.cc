#include <chrono>
#include <iostream>

#include "helper.h"
// #include "selection_sort.h"
// #include "bubble_sort.h"
#include "insertion_sort.h"

int arr[MAX];

int main() {
  size_t n;

  std::cout << "Enter n : ";
  std::cin >> n;

  if (n > MAX) {
    std::cerr << "Invalid Size\n";
    return 1;
  }

  generate_random_elements(arr, n);

  std::cout << "Sorting...\n";
  auto start = std::chrono::steady_clock::now();

  // selection_sort(arr, n);
  insertion_sort(arr,n);

  auto end = std::chrono::steady_clock::now();

  print_array(arr, n);

  auto time_taken =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Time Taken is " << time_taken.count() * 1e-9 << " s\n";

  return 0;
}
