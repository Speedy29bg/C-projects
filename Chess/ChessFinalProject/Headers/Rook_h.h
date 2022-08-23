#ifndef ROOK_H
#define ROOK_H
#include<stdbool.h>
typedef struct Rook{
    int i;
    int j;
    char rook;
 
}Rook;
 
Rook * putRookOnBoard(char ** board , Rook * rook , int i , int j);
Rook * RookMove(char ** board ,int size, char * move, int n , Rook * rook, int * NofPawns ,bool * checkForTurn);
Rook * checkForValidMoveR(char ** board ,int i , int j,int size , Rook * rook , bool * checkForTurn);
bool checkForValidMoveForPawnR(char ** board ,int i , int j ,int endi , int endj);


#endif