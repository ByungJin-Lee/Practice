//Non-overlapping Random Number Example 
//02-Pick the element of array, whenever discovered overlapping random number.
//From 0 to 15, pick 15 numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	const int array_Length = 15;
	int array[array_Length];
	bool vaild = true;
	srand((unsigned)time(NULL));
	
	for(int i = 0; i < array_Length; i++)
			array[i] = rand() % 15;
	
	do{
		vaild = true;
		for(int i = 0; i < array_Length; i++){
			for(int j = 0; j < i; j++)
				if(array[i] == array[j]){
					array[j] = rand() % 15;
					vaild = false;
					break;
				}
			if(!vaild) break;
		}
	}while(!vaild);		
}
