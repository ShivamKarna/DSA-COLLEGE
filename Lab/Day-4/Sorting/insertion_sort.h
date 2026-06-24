#pragma once
#include "helper.h"

inline void insertion_sort(int arr[], size_t n) {
  for (size_t i = 1; i < n; i++) {
    size_t j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      custom_swap(&arr[j - 1], &arr[j]);
      --j;
    }
  }
}
