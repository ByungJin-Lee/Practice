#include<iostream>
#include<string>

using namespace std;

string reverseStr(string str){
	if(!str.size()) return "";
	return reverseStr(str.substr(1)) + str.substr(0,1);
}

int main(void){
	string str_1;
	getline(cin, str_1, '\n');
	str_1 = reverseStr(str_1);
	cout << str_1 << endl;
}
