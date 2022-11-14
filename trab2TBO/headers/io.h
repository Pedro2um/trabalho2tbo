#ifndef IO_H
#define IO_H
#include "graph.h"
#include "assertx.h"

//does not matter if g or q is allocated.
void read_input(FILE* input_file, int *V, int* E, int* S, int* C, int* M, int** server, int** client, int** monitor,  Graph** g);

#endif