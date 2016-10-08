#include "testFuncs.h"
#include <stdlib.h>
#include <string>
#include <iostream>

bool check_if_sorted(int* arr, int size){
  for (int i=0;i<size-1;i++){
    if (arr[i+1]<arr[i]){
      return false; // array is not sorted
    }
  }
  return true; // array is sorted
}

bool check_if_heaped(int* arr, int size){
  int lchild, rchild;
  for (int i=0;i<size;i++){ // iterate over all points in arr
    lchild = 2*i+1; rchild=2*i+2;
    if (lchild<size){ // check if left parent exists
      if (arr[lchild]>arr[i]){
	return false; // left child exceeds parent
      }
      if (rchild<size){ // check if right child exists
	if (arr[rchild]>arr[i]){
	  return false; // right child exceeds parent
	}
      }
    }
  }
  return true;
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

void test_sort(void (*sort)(int*,int), std::string sortName, int size, int max_val){
  // generate random integers
  int* arr = generate_arr(size, max_val);
  // print_arr(arr, size, 8);

  // sort list
  sort(arr, size);
  std::cout << sortName << ": "
	    << (check_if_sorted(arr, size) ? "PASSED" : "FAILED")
            << std::endl;
  // print_arr(arr, size, 8);

  remove_arr(arr);
}

void test_heap(void (*my_heapify)(int*,int), std::string heapifyName, int size, int max_val){
  // generate random integers
  int* arr = generate_arr(size, max_val);
  // print_arr(arr, size, 8);

  // sort list
  my_heapify(arr, size);
  std::cout << heapifyName << ": "
	    << (check_if_heaped(arr, size) ? "PASSED" : "FAILED")
            << std::endl;
  // print_arr(arr, size, 8);

  remove_arr(arr);
}

void print_arr(int* arr, int size, int num_cols){
  std::cout << std::endl;
  for (int i=0;i<size;i++){
    std::cout << arr[i] << ((i%num_cols == num_cols-1) ? "\n" : "\t");
  }
  std::cout << std::endl;
}
