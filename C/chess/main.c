/*
	This is a Chess Game program.
	2020/11/17 ~ 2020/11/18
	copyright ByungJin.dev@gmail.com
*/


#include <stdio.h>
#include <stdlib.h>
#include "chessModel.h"

int main() {
	short turnTeam = 0;
	struct position (*board)[8] = makeBoard();	
	spotHorse(board);
	//make board and create Horse
	while (1) {
		displayBoard(board, turnTeam);
		//view Board
		printf("말의 위치와 이동 위치 입력\n");
		do {
			short result = boardTurn(board, &turnTeam);
			if (result == 0)
				break;
		} while (1);
		//input Position and mov Horse
		if (turnTeam == 3)
			break;

		turnTeam = (turnTeam != 1) ? 1 : 0;
		//change Turn
	}
	displayBoard(board, turnTeam);
	//display Board
	free(board);
}