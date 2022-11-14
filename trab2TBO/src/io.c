#include "io.h"

#define SERVER 1
#define CLIENT 2
#define MONITOR 3




//does not matter if g or q is allocated.
void read_input(FILE* input_file, int *V, int* E, int* S, int* C, int* M, int** server, int** client, int** monitor,  Graph** g){
        fscanf(input_file, "%d %d", V, E);
        printf("%d %d\n", (*V), (*E));

        fscanf(input_file, "%d %d %d", S, C, M);
        printf("%d %d %d\n", (*S), (*C), (*M));

        *g = graph_init((*V));

        //*map_values = malloc((*V)*sizeof(int));
        //assertx((*map_values)!=NULL, "MAP_VALUES ARRAY IS NULL");

        *server = malloc((*S)*sizeof(int));
        assertx((*server)!= NULL, "SERVER ARRAY IS NULL");

        *client = malloc((*C)*sizeof(int));
        assertx((*client)!= NULL, "CLIENT ARRAY IS NULL");

        *monitor = malloc((*M)*sizeof(int));
        assertx((*monitor)!= NULL, "MONITOR ARRAY IS NULL");
       
        puts("SERVERS:");
        for(int s = 0; s < (*S); s++){
                int v;
                fscanf(input_file, "%d", &v);
                (*server)[s] = v;
                graph_set_vertex_type((*g), v,  SERVER);
                printf("%d, TYPE OF VERTEX = %d \n", v, (int)graph_get_vertex_type((*g), v)); //debug
                
        }
        puts("\nCLIENTS:"); //debug
        for(int c = 0; c < (*C); c++){
                int v;
                fscanf(input_file, "%d", &v);
                (*client)[c] = v;
                graph_set_vertex_type((*g), v,  CLIENT);
                printf("%d, TYPE OF VERTEX = %d \n", v, (int)graph_get_vertex_type( (*g), v));//debug
                
        }
        puts("\nMONITORS:"); //debug
        for(int m = 0; m < (*M); m++){
                int v;
                fscanf(input_file, "%d", &v);
                (*monitor)[m] = v;
                graph_set_vertex_type((*g), v,  MONITOR);
                printf("%d , TYPE OF VERTEX = %d \n", v,  (int)graph_get_vertex_type((*g), v));//debug
        }


        //INITIALIZING THE ADJACENCY

        puts("\nADJ:"); //debug
        for(int e = 0; e < (*E); e++){
                int x, y;
                double z;
                fscanf(input_file, "%d %d %lf", &x, &y, &z);
                graph_set_edge((*g), x, y, z);

                printf("matrix[%d][%d] = %lf\n", x, y, graph_get_edge((*g), x, y));

                //trying to do the adjacency_list
                graph_set_edge_list((*g), x, y, z, NULL);

        }
        graph_print_adjacency((*g));

        //printf("matrix[%d][%d] = %lf\n", x, y, graph_get_edge((*g), x, y)); 
}
