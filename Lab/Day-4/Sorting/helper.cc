#include "helper.h"
#include <cstdlib>
#include <iostream>

void custom_swap(int *p, int *q) {
  int temp = *q;
  *p = *q;
  *q = temp;
}

void generate_random_elements(int arr[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    arr[i] = rand() % 1000000;
  }
}

void print_array(const int arr[], size_t n) {
  for (size_t i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  std::cout << "\n";
}
