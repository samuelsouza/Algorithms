/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Assignment 4 - Cleared Checks 
 * Mar,5th
 *
 * Samuel Camargo de Souza
 * scamarg1@binghamton.edu
 * Tested on:
 *   - Ubuntu 14.04.1 LTS (Kernel 3.13.0-32-generic)(gcc 4.8.2)
 *   - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Compiled with:
 * gcc scamarg1.c -o scamarg1
 * Example of command executed during tests:
 * ./scamarg1.c < check1.txt > out
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

int data[MAXSIZE];
int dataTemp[MAXSIZE]; //initialized as -1, keep track of the values of data[j] that sum to k
int amountDeducted;
int n;

void clearedChecks(int *data, int *dataTemp, int amountDeducted, int n){
    int i;
    int j;
    int k;
    
    dataTemp[0]=0;//set 0 to get into the first iteration
    for (i=0;i<amountDeducted;i++){
        if (dataTemp[i]!=(-1)){//it is part of the sum
            for (j=dataTemp[i]+1;j<=n;j++){
                k=i+data[j];
                if (dataTemp[k]==(-1) || dataTemp[k]>j){//check if the value must be updated
                    dataTemp[k]=j;//save value to bactrack
                }
            }
        }
    }
    //if the -1 remained in the temp at amountDeducted position, the algorithm have not converged to a possible combination
    if (dataTemp[amountDeducted]==(-1)){
        printf("Not possible\n");
    }
    else
    {
        int ad=amountDeducted; //go over dataTemp[] looking for valid data[] positions to print
        while (ad>0){
            printf("%d\n",dataTemp[ad]);// print the check index 
            ad = ad - data[dataTemp[ad]];  // Remove the value already printed
        }
    }
}

int main(){
	int y;
	scanf("%d", &amountDeducted);
    	scanf("%d", &n);
    
	for (y = 1; y <= n; ++y){
		scanf("%d", &data[y]);
    	}
    	for (y=1;y<=amountDeducted;y++){
        	dataTemp[y]=(-1);
    	}

        clearedChecks(data, dataTemp, amountDeducted, n);
}


