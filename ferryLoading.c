/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 6 - Ferry Loading
 * Mar,24th
 *
 * Samuel Camargo de Souza
 * scamarg1@binghamton.edu
 *
 * Tested on:
 *   - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Compiled with:
 * gcc scamarg1.c -o scamarg1
 * Example of command executed during tests:
 * ./scamarg1 < ferry1.txt > ferry1-out.txt
 */

#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000
int left[MAXSIZE][MAXSIZE];
int verified[MAXSIZE][MAXSIZE];
int data[MAXSIZE];

//recursive in-order printing
void printInOrder(int lastInteraction, int n) {
    if (!lastInteraction) {
		return;
  	}
	printInOrder(lastInteraction - 1, left[lastInteraction][n]);
	if(left[lastInteraction][n] == n){
		printf("R\n");
	}else{
        printf("L\n");
	}
}

 //verify the matrix results
 void printTest(int c){
    int x,z;
    for(x=0;x<=c;x++){
	printf("%d",x);
        for(z=0;z<=c;z++){
            printf("%d",verified[x][z]);
        }
        printf("\n");
    }
 
}

void ferryLoading(int n, int c){
    verified[0][0] = -1; //init the left track
    int x;
    int boarded = 0;
    int lastInteraction = 0;//keep the total cars boarded in the last interaction
    
    for(x = 1; x <= c; x++){
        scanf("%d", &data[x]);//read one car each time, analyze & fill the prob matrices
        boarded = boarded + data[x];
        
        for (int i = 0; i <= n; i++){
            if (boarded - i <= n && verified[x - 1][i]){
                verified[x][i] = -1;
                left[x][i] = i;
                lastInteraction = x;
            }
            else if (i >= data[x] && verified[x - 1][i - data[x]]){
                verified[x][i] = -1;
                left[x][i] = i - data[x];
                lastInteraction = x;
            }
        }
    }
    printTest(c); //actually print the final table
    printf("%d\n", lastInteraction);
    printInOrder(lastInteraction, n);
}

int main() {
    int n,c;
    scanf("%d", &n); //ferry length in meters
    scanf("%d", &c); //total of cars

    ferryLoading(n,c);
}

