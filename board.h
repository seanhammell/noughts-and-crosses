#ifndef BOARD
#define BOARD

#include <stdio.h>

#define NOUGHTS_CHAR "\x1b[36mO\x1b[0m"
#define CROSSES_CHAR "\x1b[35mX\x1b[0m"

enum piece {
    NOUGHTS = 0,
    CROSSES = 1
};

/*
 * A struct storing a Noughts and Crosses position.
 * 
 * A binary bitboard representation for each marker
 * type is used for the position.
 * 
 * Example of bit order to encode for a 3x3 board
 * 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 * . . .
 * . . .
 * . . .
 * 
 * NCBoard is stored as
 * - an array of previous moves
 * - an enum representing the side to play
 * - the number of moves played
 * - a bitboard "noughts" with a 1 on any nought
 * - a bitboard "crosses" with a 1 on any cross
 */

typedef struct {
    int movelist[9];
    enum piece side;
    int nbmoves;
    unsigned short noughts;
    unsigned short crosses;
} NCBoard;

int legal(const NCBoard *position, int move);
void play(NCBoard *position, int move);
void unmake(NCBoard *position);
void playseq(NCBoard *position, char* seq);
int alignment(unsigned short position);
int gameover(NCBoard *position);
void display(const NCBoard *position);

#endif