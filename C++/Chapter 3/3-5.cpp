/*
	problem 3-5
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random{
	public:
		Random();
		int next();
		int nextInRange(int s, int l);		
};

Random::Random(){
	srand((unsigned)time(NULL));
}

int Random::next(){
	return rand();
}

int Random::nextInRange(int s, int l){
	return rand()%(l-s + 1) + s;
}

int main(void){
	Random r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for(int i = 0; i < 10; i++){
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << " 4 ������ ���� ���� 10 �� --" << endl;
	for(int i = 0; i < 10; i++){
		int n = r.nextInRange(2,4);
		cout << n << ' ';
	}
	cout << endl;
}


