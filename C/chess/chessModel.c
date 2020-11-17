#include "chessModel.h"
#include <stdlib.h>
#include <stdio.h>

short checkSpace(struct position curPos, struct position willPos) {

}

//about board

struct position (*makeBoard(void))[8] {
	struct position (*newBoard)[8] = (struct position(*)[8])malloc(sizeof(struct position) * 64);		

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {						
			if (newBoard != NULL) {
				//check null
				if (newBoard[i] != NULL) {
					//check null
					newBoard[i][j].x = i;
					newBoard[i][j].y = j;
					newBoard[i][j].onHorse = NULL;
					//reset default value
				}
			}
		}
	}
	return newBoard;
}

void displayBoard(struct position (*board)[8]) {
	printf("\n     ===========\n");
	for (int i = 0; i < 10; i++) {
		if (i < 8)
			printf("     %d|", i);
		else
			printf("      |");
		for (int j = 0; j < 8; j++) {
			if (i < 8) {				
				if (board[i][j].onHorse != NULL)
					printf("%c", (board[i][j].onHorse)->role);				
				else
					printf("-");
			}
			else {
				if (i == 8)
					printf("-");
				else
					printf("%d", j);
			}
		}
		printf("|\n");
	}
	printf("     ===========\n");
}

struct position inputPos(void) {
	int x, y;
	do {
		scanf_s("%d%d", &x, &y);
		if ((x >= 0 && x <= 7)&&(y >= 0 && y <= 7)) {
			break;
		}
	} while (1);
	struct position movPos = { x, y, NULL };
	return movPos;
}

void spotHorse(struct position (*board)[8]) {
	if (board == NULL) return;
	//check null
	for (short team = 0; team < 2; team++) {
		//repeat 2 time to display team (White/Black)
		for (short i = 0; i < 16; i++) {
			//There is 16 horse per one team
			struct horse* newHorse = (struct horse*)malloc(sizeof(struct horse));
			if (newHorse != NULL) {
				newHorse->team = team;						
				//distinguish Horse Kind using repeat Time (i)
				switch (i)
				{
				case 0:
				case 1:
					//Rook
					newHorse->role = 'R';
					break;
				case 2:
				case 3:
					//Knight
					newHorse->role = 'N';
					break;
				case 4:
				case 5:
					//Bishop
					newHorse->role = 'B';
					break;
				case 6:
					//King
					newHorse->role = 'K';
					break;
				case 7:
					//Queen
					newHorse->role = 'Q';
					break;
				default:
					newHorse->role = 'P';
					break;
				}				
				//role
				if (team == 0) {
					if (i < 8) {
						//place Horse
						if (i < 6 && i % 2 == 1)
							board[0][7 - i/2].onHorse = newHorse;
						else {
							switch (i)
							{
							case 6:
								board[0][4].onHorse = newHorse;
								break;
							case 7:
								board[0][3].onHorse = newHorse;
								break;
							default:
								board[0][i / 2].onHorse = newHorse;
								break;
							}
						}
							
					}
					else
						board[1][i-8].onHorse = newHorse;
				}
				else {
					if (i < 8) {
						//place Horse
						if (i < 6 && i % 2 == 1)
							board[7][7 - i/2].onHorse = newHorse;
						else {
							switch (i)
							{
							case 6:
								board[7][4].onHorse = newHorse;
								break;
							case 7:
								board[7][3].onHorse = newHorse;
								break;
							default:
								board[7][i / 2].onHorse = newHorse;
								break;
							}
						}
							
					}
					else
						board[6][i-8].onHorse = newHorse;
				}
			}			
		}
		
	}
}

short movHorse(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	if (board != NULL) {
		if (board[curPos.y][curPos.x].onHorse == NULL) return 2;
		//there is no Horse then stop function. Error 2 : no horse
		struct horse* curHorse = board[curPos.y][curPos.x].onHorse;
		//get Horse
		if (curHorse->team != Team) return 3;
		//if can't match Team then stop function. Error 3 : not your horse
		if (curHorse->team == (board[willPos.y][willPos.x].onHorse)->team) return 4;
		//if there is your Horse on willPos then you can't go there. Error 4 : there is alreay your horse
		short (*movType)(struct position(*board)[8], struct position curPos, struct position willPos, short Team);
		//define function pointer
		switch (curHorse->role) {
		case 'P':
			movType = movPawn;
			break;
		case 'K':
			movType = movKing;
			break;
		case 'Q':
			movType = movQueen;
			break;
		case 'R':
			movType = movRook;
			break;
		case 'B':
			movType = movBishop;
			break;			
		case 'N':
			movType = movKnight;
			break;
		default:
			movType = NULL;
			break;
		}
		//change move Type
		if (movType != NULL) {
			short result = movType(board, curPos, willPos, Team);
			if (result == 1) return 5;
			//if you choose wrong way, then you can't go WillPos position. Error 5 : you can't go there
		}			
	}
}

short movBishop(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	printf("ºñ¼ó");
}
short movKing(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	printf("Å·");
}
short movQueen(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	printf("Äý");
}
short movRook(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	printf("·è");
}
short movKnight(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	printf("³ªÀÌÆ®");
}
short movPawn(struct position(*board)[8], struct position curPos, struct position willPos, short Team) {
	printf("Æù");
}