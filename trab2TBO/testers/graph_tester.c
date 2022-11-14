#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "assertx.h"
#include "file.h"

#define SERVER 1
#define CLIENT 2
#define MONITOR 3
int main(int argc, char* argv[]){

    
    if(argc < 2){
        printf("alo\n");
    }
    assertx(argc >= 2, "Insira parametros");
    //testing the graph.h
    Graph* g = graph_init(5);

    //initializing adjacency matrix
    int i,j;
    for(i = 0; i < graph_get_qtd(g); i++){
        for(j = 0; j < graph_get_qtd(g); j++){
            graph_set_edge(g, i, j, (double)(i*graph_get_qtd(g) + j));
        }
    }

    
    //vertex types

    for(i = 0; i < graph_get_qtd(g); i++){
        graph_set_vertex_type(g, i, (char)(i%3 +'a'));
    }

    graph_print(g);

    graph_free(g);

    FILE* fe = file_open(argv[1], "r");
    char message[15];
    fscanf(fe, "%s", message);
    printf("%s\n", message);
    file_close(fe);

    return 0;
}