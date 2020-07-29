//Non-overlapping Random Number Example 
//01-Pick whole array, whenever discovered overlapping random number.
//From 0 to 15, pick 15 numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	const int array_Length = 15;
	int array[array_Length];
	bool vaild = true;
	srand((unsigned)time(NULL));
	
	do{
		for(int i = 0; i < array_Length; i++)
			array[i] = rand() % 15;
		vaild = true;
		for(int i = 0; i < array_Length; i++)
			for(int j = 0; j < i; j++)
				if(array[i] == array[j]){
					vaild = false;
					break;
				}
	}while(!vaild);	
}
