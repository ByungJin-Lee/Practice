/*
	P_Name : "RAM"
*/
#include <iostream>

using namespace std;

class Ram{
	private:
		char mem[100*1024];
		int size;
	public:
		Ram();
		~Ram();
		char read(int address);
		void write(int address, char data);
};

Ram::Ram(){
	size = 100*1024;
}

Ram::~Ram(){
	cout << "메모리가 제거됨"<<endl;
}

char Ram::read(int address){
	return mem[address];
}

void Ram::write(int address, char data){
	mem[address] = data;
}

int main(void){
	Ram ram;
	ram.write(100,20);
	ram.write(101,30);
	char res  = ram.read(100) + ram.read(101);
	ram.write(102,res);
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl;
}
