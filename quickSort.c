/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 2 - Quick sort (with Hoare partition, randomization)
 * Feb,11th
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
#include <time.h>

#define MAXSIZE 1000000

int data[MAXSIZE];
int n;

int hoarePartition(int arr[],int min, int max){
    
    int pivot = arr[rand()%(max-min)+min]; // Randomized pivot
    int i = min - 1; //lowest array position
    int j = max + 1; //highest array position
    
    while (1) {
        do j = j - 1; while (arr[j] > pivot);
        
        do i = i + 1; while(arr[i] < pivot);
    
        if(i < j){
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            //Print steps
            /*for (int z=0; z <= n-1; z++) {
                printf("%d,",arr[z]);
            }*/
            printf("\n");
        }else{
            return j;
        }
    }
}

void quicksort(int arr[], int min, int max) {
    if (min < max) {
        int q = hoarePartition(arr, min, max);
        quicksort(arr, min, q); //recursive call to sort the lower part
        quicksort(arr, q + 1, max); // recursive call to sort the higher part
    }
}

int main()
{
  int y;

    scanf("%d", &n);

    for (y = 0; y < n; ++y)
      scanf("%d", &data[y]);
    
    srand(time(NULL));
    quicksort(data,0,n-1);//n-1 because n refers to the total items in the array and must be the maximum index position, ex. 10 itens, 9 max index.

    for (y = 0; y < n; ++y)
        printf("%d\n", data[y]);

}

