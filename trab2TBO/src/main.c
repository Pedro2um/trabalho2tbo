#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"
#include "graph.h"
#include "file.h"
#include "io.h"

#define SERVER 1
#define CLIENT 2
#define MONITOR 3


int main(int argc, char* argv[]){
    assertx( !(argc <= 1) , "Insira parametros");
    int V, E, S, C, M;
    Graph* g;
    int* server;
    int* client;
    int* monitor;
    FILE* input_file = file_open(argv[1], "r");
    read_input(input_file, &V, &E, &S, &C, &M, &server, &client, &monitor, &g);
    
    //doing Dijkstra
    graph_TOTAL_Dijkstra(g);


    graph_free(g);
    free(server);
    free(client);
    free(monitor);
    
    file_close(input_file);

    
    return 0;
}
