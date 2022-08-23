#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"..\Headers\Pawn_h.h"
#include"..\Headers\Queen_h.h"

Queen * putQueenOnBoard(char ** board , Queen * queenn , int i , int j){
    Queen*queen =(Queen*)malloc(sizeof(Queen));
    queen->i = i;
    queen->j = j;
    queen->queen='q';
    board[queen->i][queen->j] = queen->queen;
    return queen;
}

Queen * checkForValidMoveQ(char ** board,char * move ,int i , int j,int size , Queen * queen , bool * checkForTurn){
   
        if(queen->i+i >=size ||queen->j+j>=size || queen->i+i<0 || queen->j+j<0){
           printf("Invalid move !\n");
            *checkForTurn=false;
            return queen; 
        }else{
            if(!checkForValidMoveForPawnQ(board ,queen->i , queen->j ,i , j)){
             printf("Invalid move !\n");
            *checkForTurn=false;
            return queen;
            }
            queen->i+=i;
            queen->j+=j;
            *checkForTurn=true;
            return queen;
        }
}
 
Queen * QueenMove(char ** board ,int size, char * move ,int n , Queen * queen ,int * NofPawns,bool *checkForTurn){
    
 
    if(strcmp(move,"u")==0){
        if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,-n , 0 ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;
    }else if(strcmp(move,"d")==0){
           if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,n , 0 ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;
    }else if(strcmp(move,"r")==0){
          if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,0 , n ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;
    }else if(strcmp(move,"l")==0){
           if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,0 , -n ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;
    }else if(strcmp(move,"ur")==0){
        if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,-n , n ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;

    }else if(strcmp(move,"ul")==0){
           if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,-n , -n ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;

    }else if(strcmp(move,"dr")==0){
           if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,n , n ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;

    }else if(strcmp(move,"dl")==0){
           if(queen->i%2==0 && queen->j%2!=0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2!= 0 && queen->j% 2 == 0){
            board[queen->i][queen->j] = '-';
            }else if(queen->i%2==0 && queen->j%2==0){
            board[queen->i][queen->j] = '#';
            }else if (queen->i%2!=0 && queen->j % 2!=0){
            board[queen->i][queen->j] = '#';
            }
        queen = checkForValidMoveQ(board,move,n , -n ,size , queen, checkForTurn);
        if(checkForPawn(board,queen->i,queen->j)){
            (*NofPawns)--;
        }
        board[queen->i][queen->j] = queen->queen;
        return queen;

    }else{
        *checkForTurn=false;
        printf("Invalid turn(turns can be l,d,u,r,dl,dr,ul,ur)\n");
        return queen;
    }
 
}

bool checkForValidMoveForPawnQ(char ** board ,int i , int j ,int endi , int endj){
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