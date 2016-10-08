#include <iostream>
#include <stdlib.h>
#include <string>

#include "sort.h"
#include "testFuncs.h"

int main(){
  const int NUM_ELEMENTS = 100;
  const int MAX_RAND_NUM = 100;

  test_sort(&bubble_sort, "Bubble Sort", NUM_ELEMENTS, MAX_RAND_NUM);
  test_sort(&insertion_sort, "Insertion Sort", NUM_ELEMENTS, MAX_RAND_NUM);
  test_sort(&selection_sort, "Selection Sort", NUM_ELEMENTS, MAX_RAND_NUM);
  test_sort(&merge_sort, "Merge Sort", NUM_ELEMENTS, MAX_RAND_NUM);
  test_heap(&heapify, "Heapify", NUM_ELEMENTS, MAX_RAND_NUM);
  test_sort(&heap_sort, "Heap Sort", NUM_ELEMENTS, MAX_RAND_NUM);
}

