#include "testFuncs.h"
#include <stdio.h>

bool check_if_sorted(int* arr, int size){
  for (int i=0;i<size-1;i++){
    if (arr[i+1]<arr[i]){
      return false; // array is not sorted
    }
  }
  return true; // array is sorted
}

int* generate_arr(int size, int max_val){
  int* arr = new int[max_val];

  // populate array with random values from 1 to max_val
  for (int i=0;i<size;i++){
    arr[i] = rand()%max_val + 1;
  }

  return arr;
}

void remove_arr(int* arr){
  delete [] arr;
}
