#pragma once

// arrays functions
void create_array(int**&, int, int);
void print_array(int**);
void input_array(int**);
void random_array(int**);
void delete_array(int**&);


// sort function
void merge_array(int**);
void quick_sort2D(int**);
typedef bool (*funcmp)(int, int);
void quick_sort2D(int**, funcmp);
// comparator for quick sort
bool comparator1(int, int);
bool comparator2(int, int);