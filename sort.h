#ifndef _SORT_H
#define _SORT_H

void swap(int* arr, int i, int j); // swap elements i and j in arr
void insert(int* arr, int curr_pos, int insert_pos); // insert element in curr_pos to the position insert_pos, moving all other elements down

void bubble_sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void selection_sort(int* arr, int size);

void heap_sort(int* arr, int size);
void merge_sort(int* arr, int size);
void quick_sort(int* arr, int size);

#endif
