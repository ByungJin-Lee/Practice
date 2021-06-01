/*
	P(1)
*/
#include <iostream>

using namespace std;

class Strg{
	int strg[5];
	int Available_strg;
	public:
		Strg(int n1, int n2, int n3, int n4, int n5);
		void showlist();
};

Strg::Strg(int n1 = -1, int n2 = -1, int n3 = -1, int n4 = -1, int n5 = -1){			
	strg[0] = n1; strg[1] = n2; strg[2] = n3; strg[3] = n4; strg[4] = n5;
	int count = 0;
	for(int i = 0; i < 5;i++ )
		if(strg[i] == -1) count++;
	Available_strg = count;
}

void Strg::showlist(){
	cout << Available_strg << ": ";
	for(int i = 0; i< 5; cout << strg[i++] << " ");
	cout << endl; 
}
int main(void){
	Strg c;
	c.showlist();
	
	Strg c1(5);
	c1.showlist();
	
	Strg c2(5,-1,7);
	c2.showlist();
	return 0;
}
