/*
	problem 3-3-2
*/
#include <iostream>
#include <string>

using namespace std;

int main(void){
	//Variables
	string str;
	int count = 0, i = 0;
	//Input
	cout << "문자열 입력>> ";
	getline(cin, str);
	//Work
	while(i < str.length()){
		i = str.find('a', i) + 1;
		if(i == 0) break;
		count++;
	}
	//Display
	cout << "문자 a는 " << count << "개 있습니다." <<endl;
	
}
