#include"..\Headers\Pawn_h.h"
#include<stdio.h>
#include<stdbool.h>

bool checkForPawn(char ** board , int i , int j){
    if(board[i][j] =='p'){
        return true;
    }
    return false;

}

void putPawnOnBoard(char ** board , int size,int i , int j){
    board[i][j]='p';
}