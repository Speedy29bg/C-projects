#ifndef QUEEN_H
#define QUEEN_H
#include<stdbool.h>

typedef struct Queen{
    int i;
    int j;
    char queen;
    
}Queen;

Queen * putQueenOnBoard(char ** board , Queen * queen, int i , int j);
Queen * QueenMove(char ** board ,int size, char * move, int n , Queen * queen, int * NofPawns ,bool * checkForTurn);
Queen * checkForValidMoveQ(char ** board,char * move ,int i , int j,int size , Queen * queen , bool * checkForTurn);
bool checkForValidMoveForPawnQ(char ** board ,int i , int j ,int endi , int endj);
#endif