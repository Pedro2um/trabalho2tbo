#include <stdlib.h>
#include <stdio.h>
#include "adjacency_list.h"
#include "assertx.h"

struct cell{
    int index;
    double weight;
    Cell* next;
};
struct adjacency_list{
    int size;
    Cell** vector;
};

Adjacency_list* adjacency_list_init(int size){
    Adjacency_list* l = (Adjacency_list*)malloc(sizeof(Adjacency_list));
    l->size = size;

    l->vector = (Cell**)calloc(size, sizeof(Cell*));
    int i;
    for(i = 0; i < size; i++){
        l->vector[i] =NULL;
    }

    return l;
}

int adjacency_list_get_qtd(Adjacency_list* l){
    return l->size;
}

void adjacency_list_create_next_neighbor(Adjacency_list* l, int source, Cell* neighbor, int index, double weight){

    //if neighbor is different than NULL, tries to create in the next neighbor of the cell
    if(neighbor){
        Cell* new = (Cell*)malloc(sizeof(Cell));
        new->index = index;
        new->weight = weight;
        new->next = NULL;
        neighbor->next = new;
        neighbor = new;
        
    }
    //if neighbor is equal to NULL, tries to create from the vector of CELLS
    else{
        Cell* new = (Cell*)malloc(sizeof(Cell));
        new->index = index;
        new->weight = weight;

        //creating a new cell in the beginning
        new->next = l->vector[source];
        l->vector[source] = new;
        
    }
}

Cell* adjacency_list_next_neighbor(Adjacency_list* l, int source, Cell* neighbor){
    //if is different than NULL, tries to look for the next neighbor of the cell
    if(neighbor != NULL){
        neighbor = (neighbor->next);
    }
    //if is equal to NULL, tries to take from the vector of CELLS
    else{
        neighbor = l->vector[source];
    }
    
    return neighbor;
}

int adjacency_list_get_index_neighbor(Cell* neighbor){
    return neighbor->index;
}

double adjacency_list_get_weight(Cell* neighbor){
    return neighbor->weight;
}

double adjacency_list_get_edge(Adjacency_list* l, int source, int final){
    Cell* aux = l->vector[source];
    Cell* last;

    while(aux != NULL){
        last = aux;
        aux = aux->next;
        if(last->index == final){
            return last->weight;
        }
    }
    assertx(0, "NAO ENCONTREI A ARESTA");
    return -1;
}

void adjacency_list_print(Adjacency_list* l){
    Cell* aux, *last;

    int i;
    for(i = 0; i < l->size; i++){
        aux = l->vector[i];
        while(aux!=NULL){
            last = aux;
            aux = aux->next;

            printf("adjacency_list[%d][%d] = %.6lf\n", i, last->index, last->weight);
        }
    }
}

void adjacency_list_free(Adjacency_list* l){
    Cell* aux, *last;

    int i;
    for(i = 0; i < l->size; i++){
        aux = l->vector[i];
        while(aux!=NULL){
            last = aux;
            aux = aux->next;

            free(last);
        }
    }
    free(l->vector);
    free(l);
}

