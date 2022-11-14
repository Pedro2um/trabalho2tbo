#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include "assertx.h"
#include <math.h>
#include <limits.h>
typedef struct binary_heap binary_heap;

binary_heap* new_binary_heap(int size);

void insert(binary_heap* a, int x, double value);

double heap_get_priority(binary_heap* a, int id);

void heap_set_priority(binary_heap* a, int id, double value);

int remove_(binary_heap* a);

int top_heap(binary_heap* a);

void delete_binary_heap(binary_heap* a);

void show_binary_heap(binary_heap* a );

int get_size_binary_heap(binary_heap* a );

#endif //HEAP_H
