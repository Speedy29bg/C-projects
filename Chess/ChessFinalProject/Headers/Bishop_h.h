#ifndef Bishop_H
#define Bishop_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Bishop{
    int i;
    int j;
    char bishop;
    
}Bishop;

Bishop * putBishopOnBoard(char ** board , Bishop * bishop , int i , int j);
Bishop * BishopMove(char ** board ,int size, char * move ,int n, Bishop * bishop,int * NofPawns , bool * CheckForTurn );
Bishop * checkForValidMoveB(char ** board,int i , int j,int size , Bishop * bishop, bool * checkForTurn);
bool checkForValidMoveForPawnB(char ** board ,int i , int j ,int endi , int endj);
#endif
