#include"..\Headers\Bishop_h.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"..\Headers\Pawn_h.h"
Bishop * putBishopOnBoard(char ** board , Bishop * bishopp , int i , int j){
    Bishop*bishop =(Bishop*)malloc(sizeof(Bishop));
    bishop->i = i;
    bishop->j = j;
    bishop->bishop='b';
    board[bishop->i][bishop->j] = bishop->bishop;
    return bishop;
}

Bishop * BishopMove(char ** board ,int size, char * move ,int n, Bishop * bishop,int * NofPawns , bool * CheckForTurn ){

     if(strcmp(move,"ul")==0){
            if(bishop->i%2==0 && bishop->j%2!=0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2!= 0 && bishop->j% 2 == 0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2==0 && bishop->j%2==0){
            board[bishop->i][bishop->j] = '#';
            }else if (bishop->i%2!=0 && bishop->j % 2!=0){
            board[bishop->i][bishop->j] = '#';
            }
         bishop = checkForValidMoveB(board,-n ,-n ,size , bishop,CheckForTurn);
          if(checkForPawn(board,bishop->i,bishop->j)){
            (*NofPawns)--;
        }
         board[bishop->i][bishop->j] = bishop->bishop;
         return bishop;
     }else if(strcmp(move,"ur")==0){
         if(bishop->i%2==0 && bishop->j%2!=0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2!= 0 && bishop->j% 2 == 0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2==0 && bishop->j%2==0){
            board[bishop->i][bishop->j] = '#';
            }else if (bishop->i%2!=0 && bishop->j % 2!=0){
            board[bishop->i][bishop->j] = '#';
            }
         bishop = checkForValidMoveB(board,-n , n ,size , bishop,CheckForTurn);
         if(checkForPawn(board,bishop->i,bishop->j)){
            (*NofPawns)--;
        }
         board[bishop->i][bishop->j] = bishop->bishop;
         return bishop;
     }else if(strcmp(move,"dl")==0){
         if(bishop->i%2==0 && bishop->j%2!=0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2!= 0 && bishop->j% 2 == 0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2==0 && bishop->j%2==0){
            board[bishop->i][bishop->j] = '#';
            }else if (bishop->i%2!=0 && bishop->j % 2!=0){
            board[bishop->i][bishop->j] = '#';
            }
         bishop = checkForValidMoveB(board,n , -n ,size , bishop,CheckForTurn);
         if(checkForPawn(board,bishop->i,bishop->j)){
            (*NofPawns)--;
        }
         board[bishop->i][bishop->j] = bishop->bishop;
         return bishop;
    }else if(strcmp(move,"dr")==0){
      if(bishop->i%2==0 && bishop->j%2!=0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2!= 0 && bishop->j% 2 == 0){
            board[bishop->i][bishop->j] = '-';
            }else if(bishop->i%2==0 && bishop->j%2==0){
            board[bishop->i][bishop->j] = '#';
            }else if (bishop->i%2!=0 && bishop->j % 2!=0){
            board[bishop->i][bishop->j] = '#';
            }
         bishop = checkForValidMoveB(board,n ,n ,size , bishop,CheckForTurn);
         if(checkForPawn(board,bishop->i,bishop->j)){
            (*NofPawns)--;
        }
         board[bishop->i][bishop->j] = bishop->bishop;
         return bishop;
     }else{
        *CheckForTurn = false;
        printf("Invalid turn(turns can be ul,ur,dr,dl)\n");
        return bishop;
     }
}

Bishop * checkForValidMoveB(char ** board ,int i , int j,int size , Bishop * bishop, bool * checkForTurn){
        if(bishop->i+i >=size || bishop->j+j>=size || bishop->i+i<0 || bishop->j+j<0){
            printf("Invalid move !\n");
            *checkForTurn=false;
            return bishop;
        }else{
            if(!checkForValidMoveForPawnB(board ,bishop->i , bishop->j ,i , j)){
             printf("Invalid move !\n");
            *checkForTurn=false;
            return bishop;
            }
            bishop->i+=i;
            bishop->j+=j;
            *checkForTurn=true;
            return bishop;
        }
}

bool checkForValidMoveForPawnB(char ** board ,int i , int j ,int endi , int endj){
    if(endi>0 && endj>0){
        for(int x = i , g=j ; x <i+endi && g<j+endj ; g++ ,x++){
            if(board[x][g] == 'p'){
                return false;
            } 
        }
    }
    if(endi<0 && endj<0){
        for(int x = i , g=j ; x >i+endi && g>j+endj ;g-- ,x--){
            if(board[x][g] == 'p'){
                return false;
            } 
        }
    }

     if(endi>0 && endj<0){
        for(int x = i , g=j ; x <i+endi && g>j+endj ;g-- ,x++){
            if(board[x][g] == 'p'){
                return false;
            } 
        }
    }

    if(endi<0 && endj>0){
        for(int x = i , g=j ; x >i+endi && g<j+endj ;g++ ,x--){
            if(board[x][g] == 'p'){
                return false;
            } 
        }
    }    
    return true;
}
