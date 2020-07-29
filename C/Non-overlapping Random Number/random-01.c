//Non-overlapping Random Number Example 
//01-Pick whole array, whenever discovered overlapping random number.
//From 0 to 15, pick 10 numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	const int array_Length = 10;
	int array[array_Length];
	srand((unsigned)time(NULL));
	for (int i = 0; i < array_Length; i++) {
		array[i] = rand() % 15;
		printf("\n%d", array[i]);
	}
}
