#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include <stdlib.h>
#include <stdio.h>


typedef struct cell Cell;
typedef struct adjacency_list Adjacency_list;


Adjacency_list* adjacency_list_init(int size);

int adjacency_list_get_qtd(Adjacency_list* l);

void adjacency_list_create_next_neighbor(Adjacency_list* l, int source, Cell* neighbor, int index, double weight);

Cell* adjacency_list_next_neighbor(Adjacency_list* l, int source, Cell* neighbor);

int adjacency_list_get_index_neighbor(Cell* neighbor);

double adjacency_list_get_weight(Cell* neighbor);

double adjacency_list_get_edge(Adjacency_list* l, int source, int final);

void adjacency_list_print(Adjacency_list* l);

void adjacency_list_free(Adjacency_list* l);













#endif