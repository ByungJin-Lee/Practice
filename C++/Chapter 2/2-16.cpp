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
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
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
	cout << "총 알파벳 수 " << count << endl;
	for(int i = 0; i < 26; i++){
		cout << (char)(97+i) << "(" << table[i] << "): ";
		for(int j = 0, size = table[i]; j < size; j++) cout << "*";
		cout << endl;
	}
}
