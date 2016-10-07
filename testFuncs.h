#ifndef _TEST_FUNCS_H
#define _TEST_FUNCS_H

#include <string>

bool check_if_sorted(int* arr, int size);
int* generate_arr(int size, int max_val);
void remove_arr(int* arr);
void test_sort(void (*sort)(int*,int), std::string sortName, int size, int max_val);
void print_arr(int* arr, int size, int num_cols);

#endif // _TEST_FUNCS_H
