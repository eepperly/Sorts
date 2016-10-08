#include <cassert>
#include "sort.h"

void swap(int* arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void insert(int* arr, int curr_pos, int insert_pos){
  assert(insert_pos<=curr_pos);
  
  int temp = arr[curr_pos];
  for (int i=curr_pos-1;i>=insert_pos;i--){ // move data
    arr[i+1] = arr[i];
  }
  arr[insert_pos] = temp; // inset original element
}

void bubble_sort(int* arr, int size){
  for (int pass=0; pass<size-1; pass++){
    for (int index=0; index<size-1-pass; index++){
      if (arr[index]>arr[index+1]){
	swap(arr, index, index+1);
      }
    }
  }
}

void insertion_sort(int* arr, int size){
  for (int i=1;i<size;i++){
    for (int j=0;j<i;j++){
      if (arr[j]>arr[i]){
	insert(arr, i, j);
      }
    }
  }
}

void selection_sort(int* arr, int size){
  int minIndex, minValue;
  for (int i=0;i<size-1;i++){
    minIndex = i;
    minValue = arr[i];
    for (int j=1+i;j<size;j++){
      if (arr[j]<minValue){
	minIndex = j;
	minValue = arr[j];
      }
    }
    insert(arr, minIndex, i);
  }
}

void merge_sort(int* arr, int size){
  if (size == 2){
    if (arr[0]>arr[1]){ swap(arr, 0, 1); }
  } else if (size > 2) {
    // create array for copying
    int arr_copy[size];

    // divide array into two halves
    int* first_half = arr;
    int first_half_size = (size+1)/2;
    int* second_half = arr+(size+1)/2;
    int second_half_size = size - first_half_size;

    // recursively sort two halves
    merge_sort(first_half, first_half_size);
    merge_sort(second_half, second_half_size);

    //merge
    int first_index = 0;
    int second_index = 0;
    int insert_index = 0;

    while (first_index<first_half_size
	   && second_index<second_half_size){
      if (first_half[first_index] < second_half[second_index]){
	arr_copy[insert_index] = first_half[first_index];
	first_index++;
      } else{
	arr_copy[insert_index] = second_half[second_index];
	second_index++;
      }
      insert_index++;
    }

    if (first_index < first_half_size){
      while (first_index  < first_half_size){
	arr_copy[insert_index] = first_half[first_index];
	insert_index++;
	first_index++;
      }
    } else{
      while (second_index < second_half_size){
	arr_copy[insert_index] = second_half[second_index];
	insert_index++;
	second_index++;
      }
    }

    // copy arr_copy back onto arr
    for (int i=0;i<size;i++){
      arr[i] = arr_copy[i];
    }
  }
}

void heapify(int* arr, int size){
  // turn arr into a max heap
  int last_parent_index = (size-1)/2;
  for (int i=last_parent_index;i>=0;--i){
    fix_heap(arr, size, i);
  }
}

void fix_heap(int* arr, int size, int index){
  int lchild = 2*index+1;
  int rchild = 2*index+2;
  bool left_biggest=false, right_biggest=false;
  if (lchild < size){
    
    left_biggest=arr[lchild]>arr[index];

    if (rchild < size){
      if (left_biggest){
	right_biggest=arr[rchild]>arr[lchild]; 
      } else {
	right_biggest=arr[rchild]>arr[index];
      }
    }

    if (right_biggest){
      swap(arr, index, rchild);
      fix_heap(arr, size, rchild);
    } else if (left_biggest){
      swap(arr, index, lchild);
      fix_heap(arr, size, lchild);
    }
  }
}

void heap_sort(int* arr, int size){
  heapify(arr, size);
  for (int i=0;i<size-1;++i){
    swap(arr, 0, size-i-1);
    fix_heap(arr, size-i-1, 0);
  }
}
