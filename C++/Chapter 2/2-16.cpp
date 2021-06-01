/*
	problem 2-16
*/
#include <iostream>

using namespace std;

int main(void){
	//Variables
	char str[10001];
	int table[26];
	int index = 0, count = 0;	
	//Input
	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;
	cin.getline(str, 10000, ';');	
	//Init
	for(int i = 0; i < 26; i++) table[i] = 0;	
	//Work
	while(str[index] != 0){		
		//Check alpha
		if(str[index] >= 'a' && str[index] <= 'z'){			
			table[str[index] - 'a']++;
			count++;
		}			
		else if(str[index] >= 'A' && str[index] <= 'Z'){
			table[str[index] - 'A']++;			
			count++;
		}
		index++;
	}
	//Display	
	cout << "�� ���ĺ� �� " << count << endl;
	for(int i = 0; i < 26; i++){
		cout << (char)(97+i) << "(" << table[i] << "): ";
		for(int j = 0, size = table[i]; j < size; j++) cout << "*";
		cout << endl;
	}
}
