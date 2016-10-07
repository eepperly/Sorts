#include <cassert>

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
