/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 3 - Heap sort (with efficient Heap Building)
 * Feb,19th
 *
 * Samuel Camargo de Souza
 * scamarg1@binghamton.edu
 * Tested on:
 *   - Ubuntu 14.04.1 LTS (Kernel 3.13.0-32-generic)(gcc 4.8.2)
 *   - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Example of command executed during tests:
 * ./scamarg1.c < randomOrder.txt > out
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000000

int data[MAXSIZE];
int n;

void maxHeapify(int *data, int i, int n){

	int largest=i;
	int l = i*2;
	int r = l+1;
	if(l <= n && data[l] > data[largest]){
		largest = l;
	}
	if(r <= n && data[r] > data[largest]){
		largest = r;	
	}
	if(largest != i){
		int temp = data[i]; data[i] = data[largest]; data[largest] = temp;
		maxHeapify(data, largest, n);
	}
}

void buildMaxHeap(int *data, int n){
	for(int i = n/2; i >= 0; i--){
		maxHeapify(data,i,n);
	}
}


void heapSort(int *data, int n){
	buildMaxHeap(data, n);
	for(int i = n; i > 0; i--){
		int temp = data[0]; data[0] = data[i]; data[i] = temp;
		n--;
		maxHeapify(data,0,n);
	}
}


int main(){
	int y;
	scanf("%d", &n);

	for (y = 0; y < n; ++y)
		scanf("%d", &data[y]);

	heapSort(data, n-1);


    	for (y = 0; y < n; ++y)
        	printf("%d\n", data[y]);
}

