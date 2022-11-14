#include "../headers/heap.h"
//
// Created by user on 7/24/2022.
//

// Used for heap
#define     property(arr, i, j, compare)                    ( compare((arr)[(i)], (arr)[(j)]) )

// Used for max heap
#define     max_property_satisfied(arr, i, j, compare)      ( property( (arr), (i), (j), (compare)) >= 0 )

// Used for min heap
#define     min_property_satisfied(arr, i, j, compare)      ( property((arr), (i), (j), (compare)) <= 0 )

#define     MIN_HEAP_FLAG       INT_MAX
#define     MAX_HEAP_FLAG       INT_MIN

//change here
#define     FLAG        MIN_HEAP_FLAG

struct binary_heap{
    //h is only for indices
    int* h;//4bytes
    int n;//4dbytes
    int max_size;//4bytes
    double* map_values;//8bytes
    //int* map_id;//4bytes
};

typedef struct binary_heap binary_heap;

binary_heap* new_binary_heap(int size){
    binary_heap* new_heap = calloc(1, sizeof(binary_heap));
    if(new_heap==NULL) {
        fprintf(stderr,"ERROR, NEW HEAP IS NOT ALLOCATED\n");
        exit(1);
    }
    new_heap->h = malloc((size+1)*sizeof(int));
    assertx( (new_heap->h) !=NULL, "ERRO, NEW ARRAY IS NULL");

   // new_heap->map_id = malloc((size+1)*sizeof(int));
   // assertx(new_heap->map_id != NULL, "ERRO, MAP_ID ARRAY IS NULL");

    new_heap->map_values = malloc((size+1)*sizeof(double));
    assertx(new_heap->map_values != NULL, "ERRO, MAP_VALUES ARRAY IS NULL");

    new_heap->max_size = size;
    return new_heap;
}

static void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;

    //a->map_id[(*x)] = *x;
    //a->map_id[(*y)] = *y;
}



//x > y ?
static int greater(double x, double y){
    //const double eps = 1e-9;
    if( x > y) return 0;
    return 1;
}
//x < y ?
static int less(double x, double y){
    //const double eps = 1e-9;
    if( x < y ) return 0;
    return 1;
}

static int cmp(double x, double y){
    if(greater(x, y)) return 1;
    else if( less(x,y) ) return -1;
    return 0;
}

static void sift_up(binary_heap* a, int i){
    if(a==NULL) return;
    
    while(i > 0 &&  !greater(a->map_values[a->h[((i-1)/2)]], a->map_values[a->h[i]]) ){
        swap(&(a->h[i]), &(a->h[(i-1)/2]) );
        i = (i-1)/2;
    }
}

void insert(binary_heap* a, int x, double value){
    if(a==NULL) return;
    if(a->n == a->max_size){
        return;//heap is full
    }
    a->h[a->n] = x;
    //a->map_id[x] = a->n;
    a->map_values[x] = value;
    a->n++;
    sift_up(a, (a->n) - 1);
}


static void sift_down(binary_heap* a, int i){
    if(a==NULL) return;
    int j= 0;

    //1 >= child
    while( 2*i + 1 < a->n){

        //take the child with the biggest priority ( in this case, min(left_child, right_child) )
        j = 2*i + 1;
        if( (2*i + 2) < (a->n) && cmp( a->map_values[a->h[2*i+2]] , a->map_values[a->h[j]] ) < 0 ){
            j = 2*i + 2;
        }

        //keeps the property, dad has bigger or equal priority ( in this case, dad <= min(left_child, right_child))
        if( cmp( a->map_values[a->h[i]], a->map_values[a->h[j]]) <= 0){
            break;
        }
        else {
            swap( &(a->h[j]), &(a->h[i]));
            i = j;
        }

    }
}

int remove_(binary_heap* a){
    if(a==NULL) return FLAG;
    if(a->n == 0){
        return FLAG; //flag
    }

    printf("swaped: %d,%d returned: ",a->h[a->n-1], a->h[0]);
    swap(&(a->h[a->n-1]), &(a->h[0]));
    a->n--;
    sift_down(a, 0);
    printf("%d\n",a->h[a->n]);

    return a->h[a->n];
}

//for user only!
double heap_get_priority(binary_heap* a, int id){
    return a->map_values[a->h[id]];
}

void heap_set_priority(binary_heap* a, int id, double value){
    if(a==NULL) return;
    int idx = a->h[id];
    a->map_values[idx] = value;
    sift_up(a, idx);
}


int top_heap(binary_heap* a){
    if(a==NULL || a->n == 0) return FLAG;
    return  a->h[0];
}

void delete_binary_heap(binary_heap* a){
    if(a==NULL) return;
    if(a->h)free(a->h);
    //if(a->map_id)free(a->map_id);
    if(a->map_values)free(a->map_values);
    free(a);
}

/*static int heap_get_id(binary_heap* a, int idx){
    return a->map_id[idx];
}*/
void show_binary_heap(binary_heap* a ){
    if(a==NULL) return;
    for(int i =0; i < a->n; i ++){

        printf("heap_id = %d, map_values = %lf \n", i, heap_get_priority(a, i) );

    }
    puts("");
    return ;
}

int get_size_binary_heap(binary_heap* a ){
    if(a==NULL) return -FLAG;
    return a->n;
}

