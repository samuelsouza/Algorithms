 /*
 * Insertion Sort
 * Samuel Souza
 * Feb/02/2015
 * Tested on:
 *      - Ubuntu 14.04.1 LTS (Kernel 3.13.0-32-generic)(gcc 4.8.2)
 *      - OSX Yosemite 10.10.2 (Darwin Kernel 14.1.0)(clang-600.0.56)
 * Example of command executed during tests:
 * ./p01 < randomOrder.txt > out
*/

#include <stdio.h>

#define MAXSIZE 100000

int data[MAXSIZE];
int n;

int main()
{
  int i;

  scanf("%d", &n);

  for (i = 0; i < n; ++i)
    scanf("%d", &data[i]);

// Start Sorting
  	for(int j = 1; j<n;j++){
		int key = data[j]; //control the position of the key over the array index
		int i = j;

		while (i>=1 && data[i-1] > key){	//check if the values with lower index have a smaller value, attention to avoid negative values
			int temp = data[i]; //store the actual index value in a temp to swap positions
			data[i] = data[i-1]; //move data value to the left
			data[i-1] = temp; //retrieve the value from the temp and complete the swap.
			i = i-1;
		}
	}

// Printing Results
  for (i = 0; i < n; ++i)
    printf("%d\n", data[i]);
}
