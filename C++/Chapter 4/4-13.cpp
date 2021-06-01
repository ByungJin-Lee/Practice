/*
	problem 4-13
*/
#include <iostream>
#include <string>

using namespace std;

class Histogram{
	private:
		string str;
		int count;
		int table[26];
	public:
		Histogram(string _str);
		void put(string _str);
		void putc(char _chr);
		void print();		
};

Histogram::Histogram(string _str){
	count = 0;
	for(int i = 0; i < 26; table[i++] = 0);
	str = _str;
}
void Histogram::put(string _str){
	str.append(_str);
}
void Histogram::putc(char _chr){
	str.push_back(_chr);
}
void Histogram::print(){
	int i = 0;
	while(str[i] != 0){
		if(str[i] >= 'a' && str[i] <= 'z'){
			table[str[i] - 'a']++;
			count++;
		}else if(str[i] >= 'A' && str[i] <= 'Z'){
			table[str[i] - 'A']++;
			count++;
		}
		i++;
	}
	cout << "ÃÑ ¾ËÆÄºª ¼ö " << count << endl << endl;
	for(int i = 0; i < 26; i++){
		cout << (char)(i+97) << "\t(" << table[i] << ")\t:";
		for(int j = 0, size = table[i]; j < size; j++) cout << "*";
		cout << endl;
	}
}

int main(void){
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help,");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
