#include <iostream>
#include <stdlib.h>

#include "sort.h"

int main(){
  const int NUM_ELEMENTS = 100;
  const int MAX_RAND_NUM = 100;

  // generate random integers
  int* arr = new int[100];
  for (int i=0;i<NUM_ELEMENTS;i++){
    arr[i] = rand()%MAX_RAND_NUM+1;
  }

  // sort list
  bubble_sort(arr, NUM_ELEMENTS);
  
  // print sorted list
  for (int i=0;i<NUM_ELEMENTS;i++){
    std::cout << arr[i] << std::endl;
  }

  delete [] arr;
}
