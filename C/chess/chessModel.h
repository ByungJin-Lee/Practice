#pragma once

//Chess border size

struct horse {
	char role;
	//a kind, this horse K/Q/L/B/N/P	
	short team;
	//0 = red, 1 = blue
};

struct position {
	//position
	short x;
	short y;		
	//horse
	struct horse* onHorse;
};

/* about border */

struct position (*makeBoard(void))[8];
//make Border!
void displayBoard(struct position (*board)[8]);


/* about horse */
void spotHorse(struct position (*board)[8]);
struct position inputPos(void);
short movHorse(struct position (*board)[8], struct position curPos, struct position willPos, short Team);
//mov function
short checkSpace(struct position curPos, struct position willPos);
//checkSpace function


//horse type
short movBishop(struct position(*board)[8], struct position curPos, struct position willPos, short Team);
short movKing(struct position(*board)[8], struct position curPos, struct position willPos, short Team);
short movQueen(struct position(*board)[8], struct position curPos, struct position willPos, short Team);
short movRook(struct position(*board)[8], struct position curPos, struct position willPos, short Team);
short movKnight(struct position(*board)[8], struct position curPos, struct position willPos, short Team);
short movPawn(struct position(*board)[8], struct position curPos, struct position willPos, short Team);