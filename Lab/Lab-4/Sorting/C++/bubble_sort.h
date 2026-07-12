#pragma once
#include "helper.h"

inline void bubble_sort(int arr[], size_t n) {
  if (n == 0)
    return;
  for (size_t i = 0; i < n - 1; i++) {
    for (size_t j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        custom_swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}
