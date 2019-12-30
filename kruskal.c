/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 7 - kruskal - minimum Spanning Trees (Matrix implementation)
 * Apr,21th
 *
 * Samuel Camargo de Souza
 * scamarg1@binghamton.edu
 *
 * Tested on:
 *   - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Compiled with:
 * gcc scamarg1.c -o scamarg1
 * Example of command executed during tests:
 * ./scamarg1 < mst_test1.txt
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 10000

int matrix[MAXSIZE][MAXSIZE];
int parent[MAXSIZE];

typedef struct connection{
    int from;
    int to;
    int cost;
}connection;

connection C[MAXSIZE];


int comparing(const void * x,const void * y){
    return (*(connection *)x).cost - (*(connection *)y).cost;
}

int findSet(int v){
    if(parent[v]==-1){
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void kruskal(int v, int e){
    
    int from;
    int to;
    int cost;
    int totE = 0;
    int ePos=0;
    connection now;
    
    for(int i=0;i<v;i++){
        parent[i]=-1;
    }
    
    memset(matrix,-1,sizeof(matrix));
    qsort(C, e, sizeof(connection), comparing);
    
    while(totE < v - 1){
        now = C[ePos++];
        from = now.from;
        to = now.to;
        cost = now.cost;

        int parent1 = findSet(from);
        int parent2 = findSet(to);
        if(parent1 != parent2){
            matrix[from][to] = cost;
            parent[parent1] = parent2;
            totE++;
        }
    }
}

void printingFinal(int v){
    
    int i,j;
    int totCost = 0;
    
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(matrix[i][j]!=-1){
                totCost += matrix[i][j];
                printf("%d %d %d\n",i,j,matrix[i][j]);
            }
        }
    }
    printf("Total cost: %d\n",totCost);
}


int main()
{
    int v,e,i,j;
    
    scanf("%d %d",&v, &e);
    
    for(i=0;i<=e-1;i++){
        scanf("%d %d %d",&C[i].from, &C[i].to, &C[i].cost);
    }
    
    kruskal(v,e);
    printingFinal(v);
}
