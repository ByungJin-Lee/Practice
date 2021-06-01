/*
	problem 4-14
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class GamblingGame{
	private:
		string player[2];
		int game[3];
	public:
		GamblingGame();
		void start();
		bool roll();
		bool isWin();
};

GamblingGame::GamblingGame(){
	srand((unsigned)time(NULL));
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름>>";
	getline(cin, player[0]);
	cout << "두번째 선수 이름>>";
	getline(cin, player[1]);
}

bool GamblingGame::isWin(){
	if(game[0] == game[1] && game[1] == game[2]) return true;
	return false;
}

bool GamblingGame::roll(){
	cout << "\t\t";
	for(int i = 0; i < 3; i++){
		game[i] = rand()%3;
		cout << game[i] << "\t";
	}	
	return isWin();
}

void GamblingGame::start(){
	int pl = 0;
	string enter;
	while(1){
		cout << player[pl%2] <<  ":<Enter>";
		getline(cin, enter);
		if(!roll())
			cout << "아쉽군요!" << endl;
		else{
			cout << player[pl%2] << "님 승리!!"<<endl;
			break;
		}
		pl++;
	}
}
int main(void){
	GamblingGame game;
	game.start();
}
