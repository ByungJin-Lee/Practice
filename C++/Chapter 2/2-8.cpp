/*
	problem 2-8
*/
#include <iostream>

using namespace std;

int main(){
	//Variables
	char names[5][101];
	int list[5];
	int max = 0;
	//Input
	cout << "5 ���� �̸��� ';'���� �����Ͽ� �Է��ϼ���." << endl << ">>";
	for(int i = 0; i < 5; i++)
		cin.getline(names[i], 100, ';');
	//Work
	for(int i = 0, length = 0; i < 5; i++, length = 0){		
		//Check Length
		while(names[i][length++] != 0) {}
		//Save Length
		list[i] = length - 1;
		//Compare
		max = (list[i] > list[max]) ? i : max;
	}
	//Display
	for(int i = 0; i < 5; i++)
		cout << i + 1 << " : " << names[i] <<endl;
	cout << "���� �� �̸��� " << names[max]<<endl;
	return 0;
}
