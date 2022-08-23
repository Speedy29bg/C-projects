#include"..\Headers\Pawn_h.h"
#include"..\Headers\Knight_h.h"
#include"..\Headers\PrintBoardAndCreateBoard_h.h"
#include"..\Headers\Rook_h.h"
#include"..\Headers\Queue_h.h"
#include"..\Headers\Queen_h.h"
#include"..\Headers\Bishop_h.h"

Queue * front , * rear;

void readToResultFile(int numberOfMoves){
    FILE* file = fopen("..\\FileInput\\result.txt", "w");
    
    char * saveToFile;
    int n;
    fputs("The path : ",file);
    while(front!=NULL){
       deQueue(saveToFile,&n);
       fputs(saveToFile,file);
       fprintf(file, " %d ->", n);
    }
    fputs("END",file);
    fprintf(file, "\nThe number of moves : %d", numberOfMoves);
    fclose(file); 
}

void gameForKnight(char ** board , int size , int i , int j , int NofPawns){
    char move[3];
    bool checkForTurn;
    int numberOfMoves=0;
    init();
     if(checkForPawn(board , i , j)){
            NofPawns--;
        }
    Knight * knightt = putKnightOnBoard(board,knightt,i,j);

    printTheBoard(size,board);
    
    while(NofPawns>0){ 
        printf("Enter move : ");
        scanf("%s",&move);
        knightt=knightMove(board,size,move,knightt,&NofPawns,&checkForTurn);
        printTheBoard(size,board);
        if(checkForTurn){
            enQueue(move,0);
            numberOfMoves++;
        }
    }
    printf("Path : ");
    printQueueForK();
    printf("\nThe number of moves : %d",numberOfMoves);
    readToResultFile(numberOfMoves);
    free(knightt);
}

void gameForRook(char ** board , int size , int i , int j , int NofPawns){
    char move[3];
    bool checkForTurn;
    int numberOfMoves=0;
    int moveN;
    init();
    if(checkForPawn(board , i , j)){
            NofPawns--;
        }
     Rook * rook=putRookOnBoard(board,rook,i,j);
     printTheBoard(size,board);
     while(NofPawns>0){
        printf("Enter move : ");
        scanf("%s %d",&move,&moveN);
        rook=RookMove(board,size,move,moveN,rook,&NofPawns,&checkForTurn);
        printTheBoard(size,board);
        if(checkForTurn){
            enQueue(move,moveN);
            numberOfMoves++;
        }
    }
    printf("Path : ");
    printQueueForR();
    printf("\nNumber of moves : %d",numberOfMoves);
    readToResultFile(numberOfMoves);
    free(rook);

}

void gameForQueen(char ** board , int size , int i , int j , int NofPawns){
    char move[3];
    bool checkForTurn;
    int numberOfMoves=0;
    int moveN;
    init();
    if(checkForPawn(board , i , j)){
            NofPawns--;
        }
     Queen * queenn=putQueenOnBoard(board,queenn,i,j);
     printTheBoard(size,board);
     while(NofPawns>0){
        printf("Enter move : ");
        scanf("%s %d",&move,&moveN);
        queenn=QueenMove(board,size,move,moveN,queenn,&NofPawns,&checkForTurn);
        printTheBoard(size,board);
        if(checkForTurn){
            enQueue(move,moveN);
            numberOfMoves++;
        }
    }
    printf("Path : ");
    printQueueForR();
    printf("\nThe number of moves : %d",numberOfMoves);
    readToResultFile(numberOfMoves);
    free(queenn);
}

void gameForBishop(char ** board , int size , int i , int j ,int i1,int j1, int NofPawns){
    char move[3];
    bool checkForTurn;
    int numberOfMoves=0;
    int moveN;
    char c;
    init();
    if(checkForPawn(board , i , j)){
            NofPawns--;
        }
     Bishop * bishop=putBishopOnBoard(board,bishop,i,j);
     Bishop * bishop1=putBishopOnBoard(board,bishop1,i1,j1);
     printTheBoard(size,board);
     while(NofPawns>0){
        while(1){
        printf("Choose bishop w/b :");
        scanf(" %c",&c);
        if(c== 'w' || c == 'b'){
            break;
        }else{
            printf("You need to choose (w or b)!!\n");
        }
        }
        printf("Enter move : ");
        scanf("%s %d",&move,&moveN);
        if(c == 'b'){
            bishop1=BishopMove(board,size,move,moveN,bishop1,&NofPawns,&checkForTurn);
        }else{
            bishop=BishopMove(board,size,move,moveN,bishop,&NofPawns,&checkForTurn);
        }
        
        printTheBoard(size,board);
        if(checkForTurn){
            enQueue(move,moveN);
            numberOfMoves++;
        }
    }
   
    printQueueForR();
    printf("\n%d",numberOfMoves);
    readToResultFile(numberOfMoves);
    free(bishop1);
    free(bishop);

}

