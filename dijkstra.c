/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 8 - dijkstra - (priority queue and linked list)
 * Apr,28th
 *
 * Samuel Camargo de Souza
 * scamarg1@binghamton.edu
 *
 * Tested on:
 *   - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Compiled with:
 * gcc scamarg1.c -o scamarg1
 * Example of command executed during tests:
 * ./scamarg1 < dijkstra1.txt
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000000

typedef struct vertex vertex, *heap_t;
typedef struct edge edge;

heap_t *heap;
int heapSize = 0;

struct edge {
    edge *from;
    vertex *to;
    int cost;
};

struct vertex {
    edge *edge;
    vertex *via; // keep track of the last connected edge
    int distance;
    int id;
    int heapIndex; //keep track of the heap position
};

//create the linked list
void add(vertex *from, vertex *to, int cost){
    edge *root = 0;
    edge *knext = 0;
    
    if (knext == root) {
        root = malloc(sizeof(edge) * (MAXSIZE + 1));
        root[MAXSIZE].from = knext;
        knext = root + MAXSIZE;
    }
    knext--;
    knext->from = from->edge;
    knext->to = to;
    knext->cost = cost;
    from->edge = knext;
}

void destination(vertex *to, vertex *via, int cost){
    int i, j;
    
    if (to->via && cost >= to->distance){
        return;
    }
    
    i = to->heapIndex;
    if (!i){
        heapSize = heapSize+1;
        i = heapSize;
    }
    to->distance = cost;
    to->via = via;
    while (i > 1 && to->distance < heap[j = i/2]->distance) {
        (heap[i] = heap[j])->heapIndex = i;
        i = j;
    }
    
    heap[i] = to;
    to->heapIndex = i;
}


vertex* extractMin(){
    vertex *to, *temp;
    int i, j;
    
    if(!heapSize){
        return 0;
    }
    
    //remove the high priority element from the heap
    to = heap[1];
    temp = heap[heapSize--];
    
    for (i = 1; i < heapSize && (j = i * 2) <= heapSize; i = j) {
        if (heap[j]->distance >= temp->distance){
            break;
        }
        if (j < heapSize && heap[j]->distance > heap[j+1]->distance){
            j++;
        }
    }
    
    heap[i] = temp;
    temp->heapIndex = i;
    
    return to;
}

void printResult(vertex *to, int v){

        printf("%d\n", to->id);
        
        if (to->id == (v-1)) {
            printf("%d\n", to->distance);
        }
    
}

void dijkstra(vertex *begining)
{
    vertex *v;
    edge *e;
    
    destination(begining, begining, 0);
    while ((v = extractMin())){
        for (e = v->edge; e; e = e->from){
            destination(e->to, v, v->distance + e->cost);
        }
    }
}

int main(void)
{
    int i;
    int v, e;
    int from,to,cost;
    scanf("%d %d",&v, &e);

    vertex *arrayVertexes = (vertex*)calloc(v,sizeof(vertex));
    heap = (heap_t*)calloc(v,sizeof(heap));
    
    //init nodes names
    for (i = 0; i < v; i++){
        arrayVertexes[i].id = i;
    }
    
    for (i=0; i < e; i++) {
        scanf("%d %d %d",&from, &to, &cost);
        add(arrayVertexes + from, arrayVertexes + to, cost);
        //reversed edges
        add(arrayVertexes + to, arrayVertexes + from, cost);
    }
    
    dijkstra(arrayVertexes);
    printResult(arrayVertexes + (v-1),v);
    
    return 0;
}
