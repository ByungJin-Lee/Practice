/*
	problem 2-5
*/
#include <iostream>

using namespace std;

int main(void){
	//Variables
	char str[101];
	int c_x = 0, index = 0;
	//Input
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(str, 100, '\n');
	//Work
	while(str[index] != 0)
		if(str[index++] == 'x') c_x++;
	//Display
	cout << "x의 개수는 " << c_x << endl;
	return 0;
}
