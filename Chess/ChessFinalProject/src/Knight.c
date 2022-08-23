#include"..\Headers\Knight_h.h"
#include"..\Headers\Pawn_h.h"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
Knight * putKnightOnBoard(char ** board , Knight * knight , int i , int j){
    Knight*knightt =(Knight*)malloc(sizeof(Knight));
    knightt->i = i;
    knightt->j = j;
    knightt->knight='k';
    board[knightt->i][knightt->j] = knightt->knight;
    return knightt;
}
Knight * checkForValidMove(int i , int j,int size , Knight * knight , bool * checkForTurn){
        if(knight->i+i >=size || knight->j+j>=size || knight->i+i<0 || knight->j+j<0){
            printf("Invalid move !\n");
            *checkForTurn=false;
            return knight;
        }else{
            knight->i+=i;
            knight->j+=j;
            *checkForTurn=true;
            return knight;
        }
}

Knight * knightMove(char ** board ,int size, char * move , Knight * knight , int * NofPawns , bool * CheckForTurn){
    

    if(strcmp(move,"ul")==0){
        if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(-2 , -1 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
    }else if(strcmp(move,"ur")==0){
        if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(-2 , 1 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
    }else if(strcmp(move,"ru")==0){
       if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(-1 , 2 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
    }else if(strcmp(move,"rd")==0){
       if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(1 , 2 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
    }else if(strcmp(move,"dl")==0){
        if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(2 , -1 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
    }else if(strcmp(move,"dr")==0){
        if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(2 , 1 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
        
    }else if(strcmp(move,"lu")==0){
        
        if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(-1 , -2 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
            (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;    
    }else if(strcmp(move,"ld")==0){
        if(knight->i%2==0 && knight->j%2!=0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2!= 0 && knight->j% 2 == 0){
            board[knight->i][knight->j] = '-';
            }else if(knight->i%2==0 && knight->j%2==0){
            board[knight->i][knight->j] = '#';
            }else if (knight->i%2!=0 && knight->j % 2!=0){
            board[knight->i][knight->j] = '#';
            }
        knight = checkForValidMove(1 , -2 ,size , knight,CheckForTurn);
        if(checkForPawn(board,knight->i,knight->j)){
           (*NofPawns)--;
        }
        board[knight->i][knight->j] = knight->knight;
        return knight;
    }else{
        *CheckForTurn=false;
        printf("Invalid turn(turns can be ld,lu,rd,ru,dr,dl,ur,ul)\n");
        return knight;
    }
}
