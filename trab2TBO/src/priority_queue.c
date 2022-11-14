
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

priority_queue* new_priority_queue(int size){
       return new_binary_heap(size); 
}
//push id
void push(priority_queue* q, int x, double value){
        insert(q, x, value);
}

double get_priority(priority_queue* q, int id){
        return heap_get_priority(q, id);
}

void set_priority(priority_queue* q, int id, double value){
        heap_set_priority(q, id, value);
}

int pop(priority_queue* q){
        return remove_(q);
}

int top(priority_queue* q){
        return top_heap(q);
}


void delete_priority_queue(priority_queue* q){
        delete_binary_heap(q);
}

int size_queue(priority_queue* q){
        return get_size_binary_heap(q);
}

void show_inside_priority_queue(priority_queue* q){
        show_binary_heap(q);
}