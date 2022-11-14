#include <stdlib.h>
#include <stdio.h>
#include "assertx.h"
#include "graph.h"
#include "priority_queue.h"
#include "adjacency_list.h"


//infinitE is 1M
#define INFINITE 1000000
//undefined is -1
#define UNDEFINED -1


struct graph{
    double** adjacency_matrix;
    int qtd_vertex;
    int* vetor_vertex;
    Adjacency_list* list;
};

Graph* graph_init(int qtd){
    //initializing the graph (just the elements)
    Graph* g = (Graph*)malloc(sizeof(Graph));
    assertx(g!=NULL, "GRAPH IS NULL");
    g->qtd_vertex = qtd;


    /*initializing adjacency matrix wich will contain only the minimum weight to edges 
        ( adjacency_matrix[x][y]>0 indicantes connection and the weight)
    */
    g->adjacency_matrix = (double**)calloc( qtd, sizeof(double*));
    assertx( (g->adjacency_matrix)!=NULL, "ADJ MATRIX IS NULL");
    int i;
    for(i = 0; i <qtd; i++){
        g->adjacency_matrix[i] = (double*)calloc( qtd, sizeof(double));
        assertx(g->adjacency_matrix[i] != NULL, "ADJ MATRIX LINE IS NULL");
    }

    g->vetor_vertex = (int*)calloc(qtd, sizeof(int));
    assertx(g->vetor_vertex!=NULL, "VECTOR OF VERTEX IS NULL");


    /*initializing the adjacency_list wich contain the structure being used to search in the graph
    */
    g->list = adjacency_list_init(qtd);

    return g;
}

int graph_get_qtd(Graph* g){
    return g->qtd_vertex;
}

void graph_set_vertex_type(Graph* g, int index, char type){
    if(g!=NULL)
        g->vetor_vertex[index] = type;
}
char graph_get_vertex_type(Graph* g, int index){
    if(g!=NULL) 
        return g->vetor_vertex[index];
    return 0;
}

void graph_set_edge(Graph* g, int line, int column, double weight){
    if(g!=NULL)
        g->adjacency_matrix[line][column] = weight;
}

double graph_get_edge(Graph* g, int line, int column){
    if(g!=NULL) 
        return  g->adjacency_matrix[line][column];
    return __DBL_MAX__;

}

void graph_set_edge_list(Graph* g, int line, int column, double weight, Cell* neighbor){
    adjacency_list_create_next_neighbor(g->list, line, neighbor, column, weight );
}

double graph_get_edge_list(Graph* g, int line, int column){
    return adjacency_list_get_edge(g->list, line, column);

}

void graph_print_adjacency(Graph* g){
    if(g==NULL) return;


    adjacency_list_print(g->list);
}

void graph_print_minimum_paths(Graph* g){
    if(g==NULL) return;

    int i,j;
    for(i = 0; i < graph_get_qtd(g); i++){
        for(j = 0; j < graph_get_qtd(g); j++){
            printf("%.4lf ",g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void graph_print_vertex(Graph* g){
    if(g==NULL) return;
    int i;
    for(i = 0; i < g->qtd_vertex; i++){
        printf("%c ", g->vetor_vertex[i]);
    }
    printf("\n");
}

void graph_print(Graph* g){
    if(g==NULL) return;
    printf("Vertex qtd: %d\n", g->qtd_vertex);
    printf("AdjacencyMatrix:\n");
    graph_print_adjacency(g);
    printf("\nVertex Types:\n");
    graph_print_vertex(g);
    printf("\n");
}

void graph_free(Graph* g){
    if(g==NULL) return;
    //free in adjacency matrix
    int i;
    for(i = 0; i <g->qtd_vertex; i++){
        free(g->adjacency_matrix[i]);
    }
    free(g->adjacency_matrix);

    //free in vetor_vertex
    free(g->vetor_vertex);

    adjacency_list_free(g->list);
    //free in graph g
    free(g);
}

/**
 * Dijkstra eh do graph.h??
 * Fazer funcoes:
 * 
 */
void graph_TOTAL_Dijkstra(Graph* g){
    int i;
    printf("\n\nTRYING TO DO TOTAL DIJKSTRA\n\n");

    for(i = 0; i < g->qtd_vertex; i++){
        graph_Dijkstra(g, i, g->adjacency_matrix[i]);
    }
    printf("\n\n");
    graph_print_minimum_paths(g);
}

void graph_Dijkstra(Graph* g, int source, double* dist){
    int size = graph_get_qtd(g);
    printf("---Beginning of a new Djikstra: %d\n", source);
    dist[source] = 0;
    //prev[source] = -1;
    priority_queue* queue = new_priority_queue(size);

    int i;
    for(i = 0; i < size; i++){
        if(i != source){
            dist[i] = INFINITE;
            //prev[i] = UNDEFINED;
        }
        //adicionar com prioridade
        push(queue, i, dist[i]);
    }

    //show_inside_priority_queue(queue);
    int u,v;
    //neighbor eh um vizinho de u na lista de adjacência
    Cell* neighbor = NULL;
    int count = 0;

    while( size_queue(queue) > 0){
        show_inside_priority_queue(queue);
        u = pop(queue);
        printf("'''%d'''\n", u);
        //stops when neighbor == NULL
        while(1){
            neighbor = adjacency_list_next_neighbor(g->list, u, neighbor);
            if(neighbor == NULL){
                //printf("SHIT");
                break;
            }
            count++;
            v = adjacency_list_get_index_neighbor(neighbor);
            printf("(%d,%d)\n", u, v);
            //melhorar o jeito de encontrar vizinho
            double edge = adjacency_list_get_weight(neighbor);

            double alt = dist[u] + edge;
            //printf("(%d,%d:%.4lf\n", u, v, dist[v]);
                if(alt < dist[v]){
                    dist[v] = alt;
                    //prev[v] = u;
                    //assertx(0, "Ate aq foi");
                    set_priority(queue, v, alt);
                    //decrease_priority(queue, v, alt);
                }

        }
    }
    delete_priority_queue(queue);
    assertx(count == 9, "Faltando analisar aresta");
    printf("Trying to do Dijkstra\n");
}

/**
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                           // Initialization
3
4      create vertex priority queue Q
5
6      for each vertex v in Graph.Vertices:
7          if v ≠ source
8              dist[v] ← INFINITE                 // Unknown distance from source to v
9              prev[v] ← UNDEFINED                // Predecessor of v
10
11         Q.add_with_priority(v, dist[v])
12
13
14     while Q is not empty:                      // The main loop
15         u ← Q.extract_min()                    // Remove and return best vertex
16         for each neighbor v of u:              // Go through all v neighbors of u
17             alt ← dist[u] + Graph.Edges(u, v)
18             if alt < dist[v]:
19                 dist[v] ← alt
20                 prev[v] ← u
21                 Q.decrease_priority(v, alt)
22
23     return dist, prev
 */