/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 5 - Optimal Binary Search Trees
 * Mar,12th
 *
 * Samuel Camargo de Souza
 * scamarg1@binghamton.edu
 * Tested on:
 *   - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Compiled with:
 * gcc scamarg1.c -o scamarg1
 * Example of command executed during tests:
 * ./scamarg1 < bst1.txt > out
*/

#include <stdio.h>

#define MAXSIZE 1000

int data[MAXSIZE]; //probabilities array
int n;

// Sum the combination of the basics values (search quantity)
int sum(int data[], int i, int j){
    int sum = 0,z;
    for(z= i; z <=j; z++){
        sum = sum + data[z];
        //printf("somando %d,",data[z]);
    }
    return sum;
}

int optimalBST(int data[], int n){
    int e[n][n];//Just memo to keep the expected search cost.
    
    // First positions it's own values
    for (int i = 0; i < n; i++){
        e[i][i] = 0;
    }
    // length is chain length.
    for (int length=2; length<=n; length++){
        // i rows e[i][j]
        for (int i=0; i<n-length+1; i++){
	        // j columns e[i][j]
            int j = i+length-1;
            e[i][j] = 999999; //just "infinite number"
            
            for(int var = i; var < j; var++){ //control combination variation (a|bc, ab|c)
                int t=0;//traversals
                //printf("i:%d,j:%d, r:%d\n",i,j,var);
                //control the movements, if have to check to right of left
                if (var > i){
                      t = t + e[i][var];//just var, not (var-1), position already adjusted
                }else{
                    t = t + 0;
                }
                if(var < j){
                      t = t + e[var+1][j];
                }else{
                    t = t + 0;
                }
                
                t = t + sum(data, i, j);
                
                if (t < e[i][j]){//check which computated combination, var value, is smaller
                    e[i][j] = t;
                }
            }
        }
    }
    return e[0][n-1];
}



int main(){
	int y;
	for (y = 0; y < n; ++y){
		scanf("%d", &data[y]);
    }
    
    printf("%d\n", optimalBST(data, n));
}


