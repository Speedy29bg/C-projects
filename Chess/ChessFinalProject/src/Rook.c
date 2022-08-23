#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"..\Headers\Pawn_h.h"
#include"..\Headers\Rook_h.h"

Rook * putRookOnBoard(char ** board , Rook * rookk , int i , int j){
    Rook*rook =(Rook*)malloc(sizeof(Rook));
    rook->i = i;
    rook->j = j;
    rook->rook='r';
    board[rook->i][rook->j] = rook->rook;
    return rook;
}

Rook * checkForValidMoveR(char ** board ,int i , int j,int size , Rook * rook , bool * checkForTurn){
        if(rook->i+i >=size ||rook->j+j>=size || rook->i+i<0 || rook->j+j<0){
            printf("Invalid move !\n");
            *checkForTurn=false;
            return rook;
        }else{
            if(!checkForValidMoveForPawnR(board ,rook->i , rook->j ,i , j)){
             printf("Invalid move !\n");
            *checkForTurn=false;
            return rook;
            }
            rook->i+=i;
            rook->j+=j;
            *checkForTurn=true;
            return rook;
        }
}
 
Rook * RookMove(char ** board ,int size, char * move ,int n , Rook * rook ,int * NofPawns,bool *checkForTurn){
    
 
    if(strcmp(move,"u")==0){
        if(rook->i%2==0 && rook->j%2!=0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2!= 0 && rook->j% 2 == 0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2==0 && rook->j%2==0){
            board[rook->i][rook->j] = '#';
            }else if (rook->i%2!=0 && rook->j % 2!=0){
            board[rook->i][rook->j] = '#';
            }
        rook = checkForValidMoveR(board,-n , 0 ,size , rook, checkForTurn);
        if(checkForPawn(board,rook->i,rook->j)){
            (*NofPawns)--;
        }
        board[rook->i][rook->j] = rook->rook;
        return rook;
    }else if(strcmp(move,"d")==0){
        if(rook->i%2==0 && rook->j%2!=0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2!= 0 && rook->j% 2 == 0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2==0 && rook->j%2==0){
            board[rook->i][rook->j] = '#';
            }else if (rook->i%2!=0 && rook->j % 2!=0){
            board[rook->i][rook->j] = '#';
            }
        rook = checkForValidMoveR(board,n , 0 ,size , rook, checkForTurn);
        if(checkForPawn(board,rook->i,rook->j)){
            (*NofPawns)--;
        }
        board[rook->i][rook->j] = rook->rook;
        return rook;
    }else if(strcmp(move,"r")==0){
        if(rook->i%2==0 && rook->j%2!=0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2!= 0 && rook->j% 2 == 0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2==0 && rook->j%2==0){
            board[rook->i][rook->j] = '#';
            }else if (rook->i%2!=0 && rook->j % 2!=0){
            board[rook->i][rook->j] = '#';
            }
        rook = checkForValidMoveR(board,0 , n ,size , rook, checkForTurn);
        if(checkForPawn(board,rook->i,rook->j)){
            (*NofPawns)--;
        }
        board[rook->i][rook->j] = rook->rook;
        return rook;
    }else if(strcmp(move,"l")==0){
        if(rook->i%2==0 && rook->j%2!=0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2!= 0 && rook->j% 2 == 0){
            board[rook->i][rook->j] = '-';
            }else if(rook->i%2==0 && rook->j%2==0){
            board[rook->i][rook->j] = '#';
            }else if (rook->i%2!=0 && rook->j % 2!=0){
            board[rook->i][rook->j] = '#';
            }
        rook = checkForValidMoveR(board,0 , -n ,size , rook, checkForTurn);
        if(checkForPawn(board,rook->i,rook->j)){
            (*NofPawns)--;
        }
        board[rook->i][rook->j] = rook->rook;
        return rook;
    }else{
        *checkForTurn=false;
        printf("Invalid turn(turns can be l,d,r,u)\n");
        return rook;
    }
 
}

bool checkForValidMoveForPawnR(char ** board ,int i , int j ,int endi , int endj){

    if(endi==0 && endj<0){
        for(int g=j ;g>j+endj ;g--){
            if(board[i][g] == 'p'){
                return false;
            } 
        }
    }
    if(endi==0 && endj>0){
        for(int g=j ; g<j+endj ;g++){
            if(board[i][g] == 'p'){
                return false;
            } 
        }
    }
    if(endi>0 && endj==0){
        for(int x = i; x <i+endi ;x++){
            if(board[x][j] == 'p'){
                return false;
            } 
        }
    }
    if(endi<0 && endj==0){
        for(int x = i ;  x >i+endi ;x--){
            if(board[x][j] == 'p'){
                return false;
            } 
        }
    }
    return true;
}