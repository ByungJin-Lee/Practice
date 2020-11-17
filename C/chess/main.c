#include <stdio.h>
#include <stdlib.h>
#include "chessModel.h"

int main() {
	short turnTeam = 0;
	struct position (*board)[8] = makeBoard();	
	spotHorse(board);
	//make board and create Horse
	while (1) {
		displayBoard(board);
		//view Board
		struct position movedPos = inputPos();
		struct position willPos = inputPos();
		movHorse(board, movedPos, willPos, turnTeam);
		//input Position and mov Horse

		turnTeam = (turnTeam != 1) ? 1 : 0;
		//change Turn
	}

	free(board);
}