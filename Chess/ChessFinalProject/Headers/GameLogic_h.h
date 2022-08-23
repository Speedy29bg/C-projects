#ifndef GAMELOGIC_H
#define GAMELOGIC_H
void gameForKnight(char ** board , int size , int i , int j , int NofPawns);
void gameForRook(char ** board , int size , int i , int j , int NofPawns);
void gameForQueen(char ** board , int size , int i , int j , int NofPawns);
void gameForBishop(char ** board , int size , int i , int j ,int i1,int j1, int NofPawns);
void readToResultFile(int numberOfMoves);
#endif