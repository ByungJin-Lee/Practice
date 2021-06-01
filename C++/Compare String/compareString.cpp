/*
	P_Name : "String Compare"
*/
#include <iostream>

using namespace std;

int compare(const char *str_1, const char *str_2){
	//Stand : str_1
	int i = 0;
	while(str_1[i] != 0 && str_2[i] != 0){
		if(str_1[i] > str_2[i]) return 1;
		else if(str_1[i] < str_2[i]) return -1;
		i++;
	}
	//There is a gap between str_1 and str_2
	if(str_1[i] == 0 && str_2[i] == 0) return 0;
	else if(str_1[i] == 0) return -1;
	else return 1;
}




int main(void){
	cout << compare("Hello", "Hello");
}
