/*
| Lecture Section: APSC 160 101
| Lab Section: APSC 160 L1R
|
| Student ID: 41184342
| Student Email: ehussain@student.ubc.ca
|
| Created on Xcode on MACOS Version  11.5
| Written on 2021-12-10 by Ebrahim Hussain.
|
| ♡ All rights reserved.
|
Purpose: E8B STRING WORK
*/

#include <stdio.h>

int stringLength(char str[]){
    int stringLength = 0;
    for( int character = 0; str[character] != '\0' ; character++ ){
        stringLength++;
    }
    return stringLength;
}

void stringCopy(char dest[], char src[]){
    int characterIndex = 0;
    for ( characterIndex = 0 ; src[characterIndex] != '\0' ; characterIndex++ ) {
        dest[characterIndex] = src[characterIndex];
    }
    dest[characterIndex++] = '\0';
}

void stringAppend(char dest[], char src[]){
    int concatenateStart = stringLength(dest);
    int i = 0;
    for ( i = 0 ; src[i] != '\0' ; i++ ){
        dest[concatenateStart + i] = src[i];
    }
    dest[concatenateStart + (i++)] = '\0'; // terminating null character
}

int main(int argc, const char * argv[]) {
    // stringLength test
    char array1[] = "length is 12";
    printf("length of array1: %d\n", stringLength(array1));
    
    // stringCopy test
    char arraySource[] = "copy this!";
    char arrayCopied[10];
    
    stringCopy(arrayCopied, arraySource);
    printf("copy array: %s\n", arrayCopied);
    
    // stringAppend test
    char start[10] = "hello ";
    char add[6] = "world";
    
    stringAppend(start, add);
    printf("added array: %s\n", start);
    
    
    
    // sprintf
    int version = 1;
    char versionString[15];
    sprintf(versionString, "%s%02d%s", "version", version, ".txt");
    printf("%s\n", versionString);
    
    
    // sscanf

    char str[10] = "";
    int num = 0;
    char input[] = "ebi 22";
    sscanf(input, "%s %d", str, &num);
    
    printf("string: %s\n", str);
    printf("number: %d\n", num);
    
    char str1[6] = "";
    char str2[6] = "";
    char input2[] = "catch 22";
    sscanf(input2, "%s %s", str1, str2);
    
    printf("string: %s\n", str1);
    printf("number: %s\n", str2);
    
    
    char str3[15] = "";
    char input3[] = "This is easy.";
    sscanf(input3, "%s", str3);
    printf("string from sentence: %s\n", str3);
}
