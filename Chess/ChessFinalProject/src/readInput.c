
#include"..\Headers\Pawn_h.h"
#include"..\Headers\PrintBoardAndCreateBoard_h.h"
#include"..\Headers\readInput_h.h"
#include"..\Headers\GameLogic_h.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>






void menu(){
    int key;
    int k;
    printf("///////////////////////////////////////////////////////////////////\n"
           "// _____                           _____                      _  //\n"
           "//|_   _|                  ___    |  __ \\                    (_) //\n"
           "//  | __   ____ _ _ __    ( _ )   | |  \\/ ___  ___  _ __ __ _ _  //\n"
           "//  | \\ \\ / / _` | '_ \\   / _ \\/\\ | | __ / _ \\/ _ \\| '__/ _` | | //\n"
           "// _| |\\ V | (_| | | | | | (_>  < | |_\\ |  __| (_) | | | (_| | | //\n"
           "// \\___/\\_/ \\__,_|_| |_|  \\___/\\/  \\____/\\___|\\___/|_|  \\__, |_| //\n"
           "//                                                       __/ |   //\n"
           "//                                                       |___/   //\n"
           "///////////////////////////////////////////////////////////////////\n\n");
    printf(" /////////////////////////////////////////\n"
            "//            Choose option:           //\n"
            "//-------------------------------------//\n"
            "//           1.Normal gameplay         //\n"
            "//           2.Read from file          //\n"
            "//           0.Exit                    //\n"
            "/////////////////////////////////////////\n ");
    scanf("%d",&key);
    switch (key)
    {
    case 1:
     printf(" /////////////////////////////////////////\n"
            "//            Choose option:           //\n"
            "//-------------------------------------//\n"
            "//    1.You are chossing position      //\n"
            "//    2.Random                         //\n"
            "/////////////////////////////////////////\n ");

        scanf("%d",&k);
        if(k==1){
        readInput();
        }else{
        readInputForRandom();
        }
        break;
    case 2:
        readInputFromFile();
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
    }
    
}

void readInput(){
    int size;
    printf("////////////////////////////////////////////\n"
            "//          Enter Board Size:[x,x]        //\n"
            "//----------------------------------------//\n"
            "//                 __    __    __    __   //\n"       
            "//   bw     8 /__////__////__////__////   //\n" 
            "//         7 ////__////__////__////__/    //\n"
            "//        6 /__////__////__////__////     //\n"
            "//       5 ////__////__////__////__/      //\n"
            "//      4 /__////__////__////__////       //\n"
            "//     3 ////__////__////__////__/        //\n"
            "//    2 /__////__////__////__////         //\n"     
            "//   1 ////__////__////__////__/          //\n"
            "//      a  b  c  d  e  f  g  h            //\n"
            "//                                        //\n"
            "////////////////////////////////////////////\n");
    scanf("%d",&size);
    char ** board = createBoard(size);
    fillTheBoard(size,board);
    char figure;
    int i;
    int j;
    int i1 , j1;
    printf("/////////////////////////////////////////////\n"
            "//Enter figure you want to use and position//\n"
            "//-----------------------------------------//\n"
            "//              k - Knigth                 //\n"  
            "//              b - Bishop                 //\n"
            "//              q - Queen                  //\n"
            "//              r - Rook                   //\n"   
            "/////////////////////////////////////////////\n");
    printf("(c d d) :");
    scanf(" %c %d %d",&figure,&i,&j);
    if((i<0 || j<0) || (i>=size || j>=size)){
        while((i<0 || j<0) || (i>=size || j>=size)){
            printf("Invalid position !!!\n");
            printf("Enter position for %c (d d)\n" , figure);
            scanf("%d %d",&i,&j);
        }

    }
     switch (figure)
        {
        case 'k':
             printf("//////////////////////////\n"
                    "//   You Chose Knight  //\n"
                    "//----------------------//\n"
                    "//         (\\=,         //\n"         
                    "//        //  .\\        //\n"
                    "//       (( \\_  \\       //\n"
                    "//        ))  `\\_)      //\n"
                    "//       (/     \\       //\n"
                    "//        | _.-'|       //\n" 
                    "//         )___(        //\n"
                    "//        (=====)       //\n"
                    "//        }====={       //\n"
                    "//       (_______)      //\n"
                    "//                      //\n"
                    "//////////////////////////\n");
        break;
 
        case 'b':
             printf("/////////////////////////////\n"
                    "//    You Choose Bishop    //\n"
                    "//-------------------------//\n"
                    "//            ()           //\n"
                    "//            /\\           //\n" 
                    "//           //\\\\          //\n"
                    "//          (    )         //\n"
                    "//           )__(          //\n"
                    "//          /____\\         //\n"
                    "//           |  |          //\n"
                    "//           |  |          //\n"
                    "//          /____\\         //\n"   
                    "//         (======)        //\n"
                    "//         }======{        //\n"
                    "//        (________)       //\n"
                    "//                         //\n"
                    "/////////////////////////////\n");
         break;
 
        case 'q':
             printf("//////////////////////////\n"
                    "//   You Choose Queen   //\n"
                    "//----------------------//\n"
                    "//          ()          //\n" 
                    "//       .-:--:-.       //\n"
				    "//        \\____/        //\n"  
                    "//        {====}        //\n"  
				    "//         )__(         //\n"
      				"//        /____\\        //\n"   
				    "//         |  |         //\n" 
     			    "//         |  |         //\n"  
    			    "//         |  |         //\n"  
     			    "//         |  |         //\n"  
    			    "//        /____\\        //\n"
				    "//       (======)       //\n"
				    "//       }======{       //\n"
   				    "//      (________)      //\n"
                    "//                      //\n"
                    "//////////////////////////\n");
 
        break;
        case 'r':
             printf("/////////////////////////\n"
                    "//   You Choose Rock   //\n"
                    "//---------------------//\n"
                    "//         __ __       //\n"
                    "//        |'-'-'|      //\n"
                    "//        |_____|      //\n"  
                    "//         |===|       //\n"
                    "//         |   |       //\n"
                    "//         |   |       //\n"
                    "//         )___(       //\n"
                    "//        (=====)      //\n"
                    "//       (_______)     //\n"
                    "//                     //\n"
                    "/////////////////////////\n");
 
        break;
        default:
            printf("Invalid input!");
            break;
        }
        sleep(1);
    if(figure=='b'){
        
        printf("Enter the second position of b:");
        scanf("%d %d",&i1,&j1);
    }
    

    int NofPawns;
    printf("///////////////////////////////\n"
            "//  Enter number of pawns :  //\n"
            "//---------------------------//\n"
            "//             __            //\n"
            "//            /  \\           //\n"
            "//            \\__/           //\n"
            "//           /____\\          //\n"
            "//            |  |           //\n"
            "//            |__|           //\n"
            "//           (====)          //\n"
            "//           }===={          //\n"
            "//          (______)         //\n"
            "//                           //\n"
            "///////////////////////////////\n");
    scanf("%d",&NofPawns);

    int pi = -2;
    int pj = -2;
    int finalNumberOfPawns = NofPawns;
    for(int i = 0 ; i < NofPawns ; i++){
        while((pi<0 || pj<0) || (pi>=size || pj>=size)){
        printf("Enter position of pawn %d (d d):",i);
        scanf("%d %d",&pi,&pj);
        if((pi<0 || pj<0) || (pi>=size || pj>=size)){
            printf("Invalid position !!!\n");
        }
        }
        if(checkForPawn(board , pi , pj)){
            finalNumberOfPawns--;
        }
        putPawnOnBoard(board,size,pi,pj);
        pi = -2;
        pj = -2;
    }
    
    if(figure == 'k'){
        gameForKnight(board ,size , i , j , finalNumberOfPawns);
    }else if(figure == 'r'){
        gameForRook(board ,size , i , j ,  finalNumberOfPawns);
    }else if(figure == 'q'){
        gameForQueen(board , size , i , j , finalNumberOfPawns);
    }else if(figure == 'b'){
        gameForBishop(board ,size , i , j ,i1,j1, finalNumberOfPawns);
    }
    free(board);

}

void readInputFromFile(){
    char path[200] ="..\\FileInput\\";
    char fileName[100];
    printf("Enter file name :");
    scanf("%s",&fileName);
    strcat(path,fileName);
    FILE* file = fopen(path,"r");
    char line[256];

    fgets(line, sizeof(line), file);
    int size =atoi(line);

    char ** board = createBoard(size);
    fillTheBoard(size,board);
         
    fgets(line, sizeof(line), file);
    char * token = strtok(line, " ");
    char figure = *token;  
    token = strtok(NULL, " ");
    int i = atoi(token);
    token = strtok(NULL, " ");
    int j = atoi(token);

    
    fgets(line,sizeof(line),file);
    int NofPawns = atoi(line);

    int p1,p2;
    int finalNumberOfPawns = NofPawns;
    for(int i = 0;i<NofPawns;i++){
        fgets(line,sizeof(line),file);
        token = strtok(line," ");
        p1 = atoi(token);
        token = strtok(NULL, " ");
        p2 = atoi(token);
        if(checkForPawn(board , p1 , p2)){
            finalNumberOfPawns--;
        }
        putPawnOnBoard(board,size,p1,p2);  
    }
    fclose(file);
    if(figure == 'k'){
        gameForKnight(board ,size , i , j , NofPawns);
    }else if(figure == 'r'){
        gameForRook(board ,size , i , j ,  NofPawns);
    }else if(figure == 'q'){
        gameForQueen(board , size , i , j , NofPawns);
    }
    
}


void readInputForRandom(){
    int size;
    printf("////////////////////////////////////////////\n"
            "//          Enter Board Size:[x,x]        //\n"
            "//----------------------------------------//\n"
            "//                 __    __    __    __   //\n"       
            "//   bw     8 /__////__////__////__////   //\n" 
            "//         7 ////__////__////__////__/    //\n"
            "//        6 /__////__////__////__////     //\n"
            "//       5 ////__////__////__////__/      //\n"
            "//      4 /__////__////__////__////       //\n"
            "//     3 ////__////__////__////__/        //\n"
            "//    2 /__////__////__////__////         //\n"     
            "//   1 ////__////__////__////__/          //\n"
            "//      a  b  c  d  e  f  g  h            //\n"
            "//                                        //\n"
            "////////////////////////////////////////////\n");
    scanf("%d",&size);
    char ** board = createBoard(size);
    fillTheBoard(size,board);
    char figure;
    
    printf("/////////////////////////////////////////////\n"
            "//     Enter figure you want to use        //\n"
            "//-----------------------------------------//\n"
            "//              k - Knigth                 //\n"  
            "//              b - Bishop                 //\n"
            "//              q - Queen                  //\n"
            "//              r - Rook                   //\n"   
            "/////////////////////////////////////////////\n");
    scanf(" %c",&figure);
    switch (figure)
        {
        case 'k':
             printf("//////////////////////////\n"
                    "//   You Choose Knigth  //\n"
                    "//----------------------//\n"
                    "//         (\\=,         //\n"         
                    "//        //  .\\        //\n"
                    "//       (( \\_  \\       //\n"
                    "//        ))  `\\_)      //\n"
                    "//       (/     \\       //\n"
                    "//        | _.-'|       //\n" 
                    "//         )___(        //\n"
                    "//        (=====)       //\n"
                    "//        }====={       //\n"
                    "//       (_______)      //\n"
                    "//                      //\n"
                    "//////////////////////////\n");
        break;
 
        case 'b':
             printf("/////////////////////////////\n"
                    "//    You Choose Bishop    //\n"
                    "//-------------------------//\n"
                    "//            ()           //\n"
                    "//            /\\           //\n" 
                    "//           //\\\\          //\n"
                    "//          (    )         //\n"
                    "//           )__(          //\n"
                    "//          /____\\         //\n"
                    "//           |  |          //\n"
                    "//           |  |          //\n"
                    "//          /____\\         //\n"   
                    "//         (======)        //\n"
                    "//         }======{        //\n"
                    "//        (________)       //\n"
                    "//                         //\n"
                    "/////////////////////////////\n");
        break;
 
 
        case 'q':
             printf("//////////////////////////\n"
                    "//   You Choose Queen   //\n"
                    "//----------------------//\n"
                    "//          ()          //\n" 
                    "//       .-:--:-.       //\n"
				    "//        \\____/        //\n"  
                    "//        {====}        //\n"  
				    "//         )__(         //\n"
      				"//        /____\\        //\n"   
				    "//         |  |         //\n" 
     			    "//         |  |         //\n"  
    			    "//         |  |         //\n"  
     			    "//         |  |         //\n"  
    			    "//        /____\\        //\n"
				    "//       (======)       //\n"
				    "//       }======{       //\n"
   				    "//      (________)      //\n"
                    "//                      //\n"
                    "//////////////////////////\n");
        break;
 
 
        case 'r':
             printf("/////////////////////////\n"
                    "//   You Choose Rock   //\n"
                    "//---------------------//\n"
                    "//         __ __       //\n"
                    "//        |'-'-'|      //\n"
                    "//        |_____|      //\n"  
                    "//         |===|       //\n"
                    "//         |   |       //\n"
                    "//         |   |       //\n"
                    "//         )___(       //\n"
                    "//        (=====)      //\n"
                    "//       (_______)     //\n"
                    "//                     //\n"
                    "/////////////////////////\n");
 
        break;
        default:
            printf("Invalid input!");
            break;
        }
    sleep(1);

    int NofPawns;
    printf("///////////////////////////////\n"
            "//  Enter number of pawns :  //\n"
            "//---------------------------//\n"
            "//             __            //\n"
            "//            /  \\           //\n"
            "//            \\__/           //\n"
            "//           /____\\          //\n"
            "//            |  |           //\n"
            "//            |__|           //\n"
            "//           (====)          //\n"
            "//           }===={          //\n"
            "//          (______)         //\n"
            "//                           //\n"
            "///////////////////////////////\n");
    scanf("%d",&NofPawns);

    int pi;
    int pj;
    int i;
    int j;
    int i1;
    int j1;
    int lower = 0;
    int upper = size-1;
    srand(time(0));
    int finalNumberOfPawns = NofPawns;

    for(int i = 0 ; i < NofPawns ; i++){
        pi = (rand() %
           (upper - lower + 1)) + lower;
        pj = (rand() %
           (upper - lower + 1)) + lower;
        if(checkForPawn(board , pi , pj)){
            finalNumberOfPawns--;
        }
        putPawnOnBoard(board,size,pi,pj);
    }
    if(figure == 'k'){
        i = (rand() %
           (upper - lower + 1)) + lower;
        j = (rand() %
           (upper - lower + 1)) + lower;
        gameForKnight(board ,size , i , j , finalNumberOfPawns);
    }else if(figure == 'r'){
        i = (rand() %
           (upper - lower + 1)) + lower;
        j = (rand() %
           (upper - lower + 1)) + lower;
        gameForRook(board ,size , i , j ,  finalNumberOfPawns);
    }else if(figure == 'q'){
        i = (rand() %
           (upper - lower + 1)) + lower;
        j = (rand() %
           (upper - lower + 1)) + lower;
        gameForQueen(board , size , i , j , finalNumberOfPawns);
    }else if(figure == 'b'){
        i = (rand() %
           (upper - lower + 1)) + lower;
        j = (rand() %
           (upper - lower + 1)) + lower;
        i1 = (rand() %
           (upper - lower + 1)) + lower;
        j1 = (rand() %
           (upper - lower + 1)) + lower;
        gameForBishop(board ,size , i , j ,i1,j1, finalNumberOfPawns);
    }
    free(board);
}



