#include "chessModel.h"
#include <stdlib.h>
#include <stdio.h>

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

void displayBoard(struct position (*board)[8], short Team) {	
	printf("\n     ===========\n");
	for (int i = 0; i < 10; i++) {
		if (i < 8)
			printf("     %d|", i);
		else
			printf("      |");
		for (int j = 0; j < 8; j++) {
			if (i < 8) {				
				if (board[i][j].onHorse != NULL) {
					if (board[i][j].onHorse->team == 0)
						red(); 
					else
						blue();
					printf("%c", (board[i][j].onHorse)->role);
					resetColor();
				}								
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
	displayTeam(Team);
}

short boardTurn(struct position(*board)[8], short* Team) {
	printf("\n");
	struct position movedPos = inputPos();
	struct position willPos = inputPos();
	printf("-------------------");
	return turnHorse(board, movedPos, willPos, Team);
}

struct position inputPos(void) {
	int x, y;	
	do {
		scanf_s("%1d%1d", &x, &y);
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
				newHorse->first = 1;
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

short turnHorse(struct position(*board)[8], struct position curPos, struct position willPos, short* Team) {
	short judge = movHorse(board, curPos, willPos, Team);
	//get error
	switch (judge)
	{
	case 2:
		printf("There is no your Horse");
		return 1;
	case 3:
		printf("The horse is not your Horse");
		return 1;
	case 4:
		printf("There is already your Horse");
		return 1;
	case 5:
		printf("The position is not right, wrong way");
		return 1;	
	}
	return 0;
}


short movHorse(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	if (board != NULL) {
		if (board[curPos.y][curPos.x].onHorse == NULL) return 2;
		//there is no Horse then stop function. Error 2 : no horse
		struct horse* curHorse = board[curPos.y][curPos.x].onHorse;
		//get Horse
		if (curHorse->team != *Team) return 3;
		//if can't match Team then stop function. Error 3 : not your horse
		if (board[willPos.y][willPos.x].onHorse != NULL && curHorse->team == (board[willPos.y][willPos.x].onHorse)->team) return 4;
		//if there is your Horse on willPos then you can't go there. Error 4 : there is alreay your horse
		short (*movType)(struct position(*board)[8], struct position curPos, struct position willPos, short *Team);
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

short movBishop(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//Bishop
	short height = willPos.y - curPos.y;
	short width = willPos.x - curPos.x;
	if (height * height == width * width) {
		//case can't mov
		short plusWidth, plusHeight;
		plusHeight = (height > 0) ? 1 : -1;
		plusWidth = (width > 0) ? 1 : -1;
		for (short i = curPos.x + plusWidth, j = curPos.y + plusHeight; i != willPos.x; i += plusWidth, j += plusHeight) {
			if (board[j][i].onHorse != NULL)
				return 1;
			//not right away : there is other Horse on way;
		}
		//case End can't mov
		changeHorse(board, curPos, willPos, Team);
		return 0;
		//right way
	}
	return 1;
	//not right way
}
short movKing(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//King
	short height = willPos.y - curPos.y;
	short width = willPos.x - curPos.x;
	if (((height* height == 0) || (height * height == 1)) && ((width * width == 0)||(width * width == 1))) {		
		changeHorse(board, curPos, willPos, Team);		
		return 0;
		//right position		
	}	
	return 1;
	//not a right position
}
short movQueen(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//Queen
	if(movRook(board, curPos, willPos, Team) == -1)
		movBishop(board, curPos, willPos, Team);
	//same Moving Type like Rook
}
short movRook(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//Rook
	short height = willPos.y - curPos.y;
	short width = willPos.x - curPos.x;
	if ((width == 0) || (height == 0)) {	
		//case can't mov
		short plusWidth = 0, plusHeight = 0;
		if (height == 0)			
			plusWidth = (width > 0) ? 1 : -1;		
		else
			plusHeight = (height > 0) ? 1 : -1;
		for (int i = curPos.x + plusWidth, j = curPos.y + plusHeight; i != willPos.x || j != willPos.y; i += plusWidth, j += plusHeight) {
			if (board[j][i].onHorse != NULL)
				return 1;							
			//not right way
		}		
		//case End can't mov
		changeHorse(board, curPos, willPos, Team);
		return 0;
	}
	return 1;
}
short movKnight(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//Knight	
	short heigth = curPos.y - willPos.y;
	short width = curPos.x - willPos.x;
	if (((heigth * heigth) + (width * width)) == 5) {
		changeHorse(board, curPos, willPos, Team);		
		return 0;
		//right position
	}
	return 1;
	//not a right position
}
short movPawn(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//Pawn

	//mov
	if ((willPos.y > curPos.y && *Team == 0) || (willPos.y < curPos.y && *Team == 1)) {
		short heigth = curPos.y - willPos.y;
		short width = curPos.x - willPos.x;
		//case 1 : attack oppsite Horse
		if (((heigth * heigth) + (width * width)) == 2) {			
			if (board[willPos.y][willPos.x].onHorse != NULL && (board[willPos.y][willPos.x].onHorse)->team != (board[curPos.y][curPos.x].onHorse)->team) {
				changeHorse(board, curPos, willPos, Team);				
				return 0;
				//right position
			}
		}
		//case can't mov
		short block = willPos.y - curPos.y;
		switch (block)
		{
		//if there is Horse between curPosition and willPosition then stop function
			//team Blue
		case -2:
			if (board[curPos.y - 1][curPos.x].onHorse != NULL)
				return 1;
			break;
			//team Red
		case 2:
			if (board[curPos.y + 1][curPos.x].onHorse != NULL)
				return 1;
			break;		
		default:
			break;
		}

		//case 2 : mov 2 block at first Time
		if ((board[curPos.y][curPos.x].onHorse)->first == 1 && heigth >= -2 && heigth <= 2 && width == 0) {
			(board[curPos.y][curPos.x].onHorse)->first = 0;
			changeHorse(board, curPos, willPos, Team);			
			return 0;
			//right position
		}
		//case 3 : mov 1 block at other Time
		else if(heigth >= -1 && heigth <= 1 && width == 0) {
			changeHorse(board, curPos, willPos, Team);						
			return 0;
			//right position
		}			
	}	
	return 1;
	//not right position
}
void changeHorse(struct position(*board)[8], struct position curPos, struct position willPos, short *Team) {
	//change Horse
	if (board != NULL) {		
		struct horse* tempPtr = board[curPos.y][curPos.x].onHorse;
		printf("-> %c ÀÌµ¿\n", tempPtr->role);
		board[curPos.y][curPos.x].onHorse = NULL;
		if (board[willPos.y][willPos.x].onHorse != NULL) {
			if(board[willPos.y][willPos.x].onHorse->role == 'K')
				*Team = 3;
			//Team 3 means Game End!
			free(board[willPos.y][willPos.x].onHorse);
			//free horse
		}
		board[willPos.y][willPos.x].onHorse = tempPtr;
		//change Horse
	}
}

/* about Utility */
void red(void) {
	printf("\033[1;31m");
}
void blue(void) {
	printf("\033[0;34m");
}
void resetColor(void) {
	printf("\033[0;m");
}
void displayTeam(short team) {
	printf("\n");
	if (team == 0)
		printf("Red Team Turn\n");
	else
		printf("Blue Team Turn\n");
}