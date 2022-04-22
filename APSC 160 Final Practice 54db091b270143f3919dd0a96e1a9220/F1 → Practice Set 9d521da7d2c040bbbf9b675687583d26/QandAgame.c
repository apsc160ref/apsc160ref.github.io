// PROJECT HEADER !!
/*
| Lecture Section: APSC 160 101
| Lab Section: APSC 160 L1R
|
| Student ID: 41184342
| Student Email: ehussain@student.ubc.ca
|
| Created on Xcode on MACOS Version  11.5
| Written on 2021-12-13 by Ebrahim Hussain.
|
| ♡ All rights reserved.
|
Purpose:
· https://www.notion.so/F1-Practice-Set-50ce18ae2bfb4982a0b701dfc2e62d39
*/

#include <stdio.h>
#include <stdlib.h>
#define DATA_FILE "game.txt"

int stringLength( char str[] ){
    int charCount = 0;
    for ( charCount = 0 ; str[charCount] != '\0' ; ++charCount ){}
    return charCount;
}

int findCharInString( char str[], char c ){
    int charIndex = 0;
    for ( charIndex = 0; str[charIndex] != '\0' ; charIndex++ ){
        if ( str[charIndex] == c )
            return charIndex;
    }
    return -1; // return false (-1) otherwise
}

void copySubstring(char dest[], char src[], int start, int length){
    int numChars = 0;
    for ( numChars = 0 ; numChars < length && src[start+numChars] != '\0' ; numChars++ ){
        dest[numChars] = src[start+numChars];
    }
    dest[numChars++] = '\0'; // add ending character
}

int separateQuestionAnswer(char str[], char question[], char answer[]){
    int questionLength = findCharInString(str, '?');
    int entireLength = stringLength(str);
    if ( questionLength <= 0 || entireLength <= questionLength + 2){
        return 0;
    }
    else{
        copySubstring(question, str, 0, questionLength);
        copySubstring(answer, str, questionLength+2, entireLength);
        return 1;
    }

}

void printStringNumbers( char str[] ){
    for(int i = 0 ; str[i] != 0 ; ++i ) {
        printf("%d ", str[i]);
    }
    printf("\n");
}

int fscanline(FILE* file, char line[])
{
    int len = 0; /* length of line */
    char c = '\0'; /* next character to read */
    int success = 0; /* success of fscanf */
    
    /* loop until end of line or file */
    success = fscanf(file, "%c", &c);
    while (success == 1 && c != '\n') {
        line[len++] = c; /* copy character */
        success = fscanf(file, "%c", &c); /* next character */
    }
    line[len] = '\0'; /* terminating NUL */
    return len;
}

int compareStringsCaseInsensitive(char str1[], char str2[]){
    // if letter is lowercase -> convert to uppercase
    // lower case letters: 97 — 122, shift down by 32 for uppercase variant
    int characterIndex = 0;
    // keep going through each character until reached stop
    for ( characterIndex = 0 ; str1[characterIndex] != 0 || str2[characterIndex] != 0 ; ++characterIndex ){
        // change any lowercases to uppercases
        int character1 = str1[characterIndex];
        int character2 = str2[characterIndex];
        if ( 97 <= character1 && character1 <= 122 ){
            character1 -= 32;
        }
        if ( 97 <= character2 && character2 <= 122 ){
            character2 -= 32;
        }
        if ( character1 != character2 ){
            return 0;
        }
    }
    return 1; // return true otherwise
}

/* scans a line from standard input */
int scanline(char line[])
{
    int len = 0; /* length of line */
    char c = '\0'; /* next character to read */
    int success = 0; /* success of scanf */
    success = scanf("%c", &c);
    while (success == 1 && c != '\n') {
        line[len++] = c; /* copy character */
        success = scanf("%c", &c); /* next character */
    }
    line[len] = '\0'; /* terminating NUL */
    return len;
}

int main ( void ){
    
    // step one, obtain two strings, question and answer
    char string[250] = {32};
    char question[250] = {32};
    char answer[250] = {32};
    char response[250] = {32};
    int questionsCorrect = 0;
    int questionsAsked = 0;
    
    FILE* inFile = fopen(DATA_FILE, "r");
       
    if (inFile == NULL)
        printf("Error opening input file - program terminating...\n");
    else {
        while (fscanline(inFile, string) > 0){

            if ( separateQuestionAnswer(string, question, answer) == 0 ) {
                break; // break if separateQuestionAnswer => FALSE, question separating failed
            }
            
            printf("%s? ", question);
            scanline(response);
            
            questionsAsked++;
            if( compareStringsCaseInsensitive(response, answer) == 1){
                questionsCorrect++;
            }
            
        }
        fclose(inFile);
        double score = 0;
        score = (double) questionsCorrect / questionsAsked;
        printf("Score: %d/%d = %.2f%%\n", questionsCorrect, questionsAsked, score*100);
    }
    return 0;

}
