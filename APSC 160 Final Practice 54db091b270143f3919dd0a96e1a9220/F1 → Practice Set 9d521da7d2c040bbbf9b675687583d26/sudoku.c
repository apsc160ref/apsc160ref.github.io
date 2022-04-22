// PROJECT HEADER !!
/*
| Lecture Section: APSC 160 101
| Lab Section: APSC 160 L1R
|
| Student ID: 41184342
| Student Email: ehussain@student.ubc.ca
|
| Created on Xcode on MACOS Version  11.5
| Written on 2021-12-14 by Ebrahim Hussain.
|
| ♡ All rights reserved.
|
Purpose:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_FILE "sudoku.txt"

int checkDigits ( int digitList[] );
void selectionSort( int data[], int size );
int indexOfSmallest( int data[], int size, int startIndex );

int main ( void ){
    
    int sudokuBoard[9][9];
    int numberTile = 0;
    int columnCounter = 0;
    int rowCounter = 0;
    int checkArray[9]={0};
    int failed = 0;         // if failed > 0, sudoku is not solved
    
    FILE* inFile = fopen(DATA_FILE, "r");
       
    if (inFile == NULL)
        printf("Error opening input file - program terminating...\n");
    else {
        while ( fscanf(inFile, "%d", &numberTile) == 1){
            // printf("%d", numberTile);
            
            sudokuBoard[rowCounter][columnCounter] = numberTile;
            
            columnCounter++;
            if (columnCounter == 9){
                // reset column counter, increment row
                columnCounter = 0;
                rowCounter++;
            }
        }
        fclose(inFile); // close the file
        
        // now that we have our 2D 9x9 array, we can run all our checks:
        
        // CHECK 1: DO ALL ROWS SATISFY CONSTRAINTS?
        for( int row = 0; row < 9 && failed == 0; row++ ){
            // build the checkArray for each row
            for( int col = 0; col < 9; col++){
                checkArray[col] = sudokuBoard[row][col];
            }
            failed = checkDigits(checkArray);   // update failed accordingly
        }
        
        // CHECK 2: DO ALL COLUMNS SATISFY CONSTRAINTS?
        for ( int col = 0; col < 9 && failed == 0; col++ ){
            // build the checkArray for each col
            for ( int row = 0; row < 9; row++ ){
                checkArray[row] = sudokuBoard[col][row];
            }
            failed = checkDigits(checkArray);   // update failed accordingly
        }
        
        // CHECK 3: DO ALL SUBBGRIDS SATISFY CONSTRAINTS?
        int colStart = 0;
        int append = 0;
        for ( int row = 0; row < 9 && failed == 0; row++ ){
            int rowStart = ((int) row/3)*3;
            colStart += 3;
            if (colStart == 9) colStart = 0;
            for ( int rowCount = rowStart ; rowCount < rowStart+3 ; rowCount++){
                for ( int colCount = colStart ; colCount < colStart+3 ; colCount++ ){
                    checkArray[append] = sudokuBoard[rowCount][colCount];
                    append++;
                }
            }
            failed = checkDigits(checkArray);
            append = 0;
        }
        
        if ( failed == 0 )
            printf("SOLVED\n");     // made it to the end, print solved
    }
    
    
    
    return 0;
}

int checkDigits ( int digitList[] ){
    /* a list of length 9 is passed into this function.
     ie. [1,2,3,4,5,6,7,8,9]. this list can represent
     any given column, block, or row. to do this, we simply
     sort the array and then check the sorted array
     is of the form listed above.
     */
    
    // step 1: sort array
    selectionSort(digitList, 9); // here we use selection sort to sort the array
    
    // step 2: look through array and make sure elements go from 1 —> 9
    for( int index = 0; index < 9; index++ ){
        if ( digitList[index] != index+1 ){     // digitList[0] = 1, digitlist[1] = 2, etc.
            if ( digitList[index] == 0 ){
                printf("UNSOLVED\n");
                return 1;                       // return UNSOLVED (blank space exists)
            }
            else{
                printf("INVALID\n");
                return 2;                       // return INVALID since digit is wrong but not blank
            }
        }
    }
    return 0;                                   // return SOLVED if all checks passed
}

void selectionSort( int data[], int size ) {
    int indexOfMin = 0;
    int temp = 0; // temporary value
    for(int startIndex = 0 ; startIndex < size ; startIndex++){
        indexOfMin = indexOfSmallest(data, size, startIndex);
        // value swapping
        temp = data[startIndex];                // store the value at startIndex
        data[startIndex] = data[indexOfMin];    // overwrite said value from indexOfMin
        data[indexOfMin] = temp;                // restore indexOfMin from temp
    }
}

int indexOfSmallest( int data[], int size, int startIndex ) {
    int currentMinIndex = startIndex; // set a current minimum index
    for (int i = startIndex; i < size ; i++){
        if (data[i] < data[currentMinIndex]){
            currentMinIndex = i; // set the new minimum index
        }
    }
    return currentMinIndex;
}
