#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9


int isValid(int mySudoku[ROWS][COLS] , int myRow , int myColumn , int number){
    int lineAux = (myRow / 3) * 3;
    int colAux = (myColumn / 3) * 3;

    for(int i = 0 ; i < ROWS ; i++){
         if (mySudoku[myRow][i] == number){
            return 0;
         }

    }

    for(int j = 0 ; j < COLS ; j++){
        if(mySudoku[j][myColumn] == number){
            return 0;
        }
    }

    for(int k = lineAux ; k < (lineAux + 3) ; k++){
        for(int l = colAux ; l < (colAux + 3) ; l++){
            if(mySudoku[k][l] == number){
                return 0;
            }
        }
    }
    return 1;
}

int solveSoduku(int mySudoku[ROWS][COLS]){
    int isZero = 0;
    int myRow , myCol , myNumber;
    for(myRow = 0 ; myRow < ROWS ; myRow++){
        for(myCol = 0 ; myCol < COLS ; myCol++){
            if(mySudoku[myRow][myCol] == 0){
                isZero = 1;
                break;
            }
        }
        if(isZero == 1){
            break;
        }
    }
    if(isZero == 0){
        return 1;
    }

    for(myNumber = 1 ; myNumber <= 9 ; myNumber++){
        if(isValid(mySudoku , myRow , myCol , myNumber)){
            mySudoku[myRow][myCol] = myNumber;

            if(solveSoduku(mySudoku) == 1){
                return 1;
            }

            mySudoku[myRow][myCol] = 0;
        }
    }

    return 0;

}

void displaySoduku(int mySoduku[ROWS][COLS]){
    for(int i = 0 ; i < ROWS ; i++){
        
    
        for(int j = 0 ; j < COLS ; j++){
            printf("%d " , mySoduku[i][j]);
            if( (j + 1) % 3 == 0 && j < COLS - 1){
                 printf("| ");
            }
           
        }
        printf("\n");

        if((i + 1) % 3 == 0 && i < ROWS -1){
            printf("------ + ------ + ------\n");
        }
    }
}

void inputSudoku(int mySudoku[ROWS][COLS]){
    printf("Welcome to the sudoku solver\n");
    printf("In the empty boxes put the number zero!\n");

    for(int i = 0 ; i < ROWS ; i++){
        printf("Line %d \n" , i + 1);
       
        for(int j = 0 ; j < COLS ; j++){
            printf("Enter the number: ");
            scanf("%d" , &mySudoku[i][j]);
            getchar();

            while(mySudoku[i][j] < 0 || mySudoku[i][j] > 9){
                printf("Please enter a number between 0 and 9\n");
                scanf("%d" , &mySudoku[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int isSolvable;
    int sudokuPuzzle[ROWS][COLS];
    inputSudoku(sudokuPuzzle);
    printf("Display puzzle: \n");
    displaySoduku(sudokuPuzzle);
    isSolvable = solveSoduku(sudokuPuzzle);
    if(isSolvable){
         printf("\n");
         printf("After: \n");
         displaySoduku(sudokuPuzzle);
    }
    else{
        printf("The soduku puzzle is unsolvable!\n");
    }
   
}

