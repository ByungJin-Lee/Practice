/*
	P_Name : "String Copy"
*/
#include <iostream>

using namespace std;

int lenString(const char *str){
	int c = 0;
	while(str[c++] != 0) {}
	return c-1;
}

void copyString(char **origin, const char *copy){
	*origin = new char[lenString(copy)+1];
	int i = 0;
	for(; copy[i] != 0; origin[0][i] = copy[i], i++);
	origin[0][i] = 0;
}

int main(){
	char *a = "hellomyname";
	char *b = "no";
	copyString(&a, b);
	cout << a << endl;
}

