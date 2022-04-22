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

int stringLength( char str[] );
int findCharInString( char str[], char c );
void copySubstring(char dest[], char src[], int start, int length);
int separateQuestionAnswer(char str[], char question[], char answer[]);
int compareStringsCaseInsensitive(char str1[], char str2[]);

int main( void ) {
    // test
    printf("TEST: STRING LENGTH\n");
    char test[] = {'a', 'a','b','a','a','a', '\0'};
    printf("%d\n", stringLength(test));

    printf("TEST: POSITION OF CHAR IN STRING\n");
    printf("%d\n", findCharInString(test, 'b'));


    printf("TEST: SUBSTRING COPY TEST\n");
    char src[] = {'a', 'b', 'c', 'd', '\0'};
    char dest[5] = {0};
    copySubstring(dest, src, 3, 7);
    printf("%s\n", dest);

    // seperate question answer
    printf("TEST: EXTRAPOLATE QUESTION DATA\n");
    char source[] = {'g', 'f', '?', ' ', 'r', 'i', 'o', 'n', 'a', '\0'};
    char q[100];
    char a[100];
    if ( separateQuestionAnswer(source, q, a) == 1 ){
        printf("question: %s\n", q);
        printf("answer: %s\n", a);
    }

    // compare two cases
    printf("TEST: COMPARING TWO STRINGS\n");
    char str1[4]={'c','a','t', '\0'};
    char str2[4]={'c','A','r', '\0'};
    printf("compare case: %d\n", compareStringsCaseInsensitive(str1, str2));

    return 0;
}

int stringLength( char str[] ){
    int charCount = 0;
    for ( charCount= 0 ; str[charCount] != '\0' ; ++charCount ){}
    return charCount;
}

int findCharInString( char str[], char c ){
    int charIndex = 0;
    for ( charIndex = 0 ; str[charIndex] != '\0' ; charIndex++ ){
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
    /*
     STRING FORM: (question)? (answer).
     question[] -> (question)
     answer[] -> (answer)
     */
    // question string goes from 0 —> findCharInString(?)
    int questionLength = findCharInString(str, '?');
    if ( questionLength != -1 ){
        copySubstring(question, str, 0, questionLength);
        copySubstring(answer, str, questionLength+2, stringLength(str));
        return 1;
    }
    else return 0; // not a valid question - answer pair
}

int compareStringsCaseInsensitive(char str1[], char str2[]){
    // if letter is lowercase -> convert to uppercase
    // lower case letters: 97 — 122, shift down by 32 for uppercase variant
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
