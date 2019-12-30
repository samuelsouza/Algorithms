/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Fibonacci Numbers - recursive, saving results in an array.
 * Mar,29th
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

#define MAX 1000
int n,temp;
int f[MAX];

int fib(int n){
    int i;
    if(f[n] != -1){
        return f[n];
    }
    if (n <= 2) {
        temp = 1;
    }else{
        temp = fib(n-1)+fib(n-2);
    }
    f[n] = temp;
    return temp;
}


int main(){
    
    scanf("%d",&n);
    for (int i=0; i<=n+1; i++) {
        f[i]=-1;
    }
    printf("%d\n", fib(n));
    
}


