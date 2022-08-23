#include<stdio.h>
#include<stdlib.h>

char **createBoard(int n){
    char ** board =(char**)malloc(sizeof(char*)*n);
    for(int i = 0 ; i < n ; i++){
        board[i] = (char*)malloc(sizeof(char)*n);
    }
    return board;
}

void fillTheBoard(int n , char ** board){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i%2==0 && j%2!=0){
            board[i][j] = '-';
            }else if(i%2!= 0 && j % 2 == 0){
            board[i][j] = '-';
            }else if(i%2==0 && j%2==0){
            board[i][j] = '#';
            }else if (i%2!=0 && j % 2!=0){
            board[i][j] = '#';
            }
            
            
        }
    }
}

void clearTheMemory(int n , char ** board){
    for(int i = 0 ; i < n ; i++){
        free(board[i]);
    }
    free(board);
}

void printTheBoard(int n , char ** board){
    for(int i = 0 ; i<n;i++){
        for(int j = 0 ; j <n; j++){
            printf(" %c ",board[i][j]);
        }
        printf("\n");
    }
}
