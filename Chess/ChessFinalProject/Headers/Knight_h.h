#ifndef KNIGHT_H
#define KNIGHT_H
#include<stdbool.h>

typedef struct Knight{
    int i;
    int j;
    char knight;
    
}Knight;

Knight * putKnightOnBoard(char ** board , Knight * knight , int i , int j);
Knight * checkForValidMove(int i , int j,int size , Knight * knight , bool * checkForTurn);
Knight * knightMove(char ** board ,int size, char * move , Knight * knight , int * NofPawns , bool * CheckForTurn);
#endif