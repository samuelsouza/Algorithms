/* Skeleton code for CS575 Spring 2015 Program 01.
 * In your submitted code, include your name and the date.
 *
 * CS575 - Fibonacci Numbers - DP
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

int n;

int fib(int n){
    int f[n+1];
    int i;
    
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}


int main(){
    
    scanf("%d",&n);
    printf("%d\n", fib(n));
    
}


