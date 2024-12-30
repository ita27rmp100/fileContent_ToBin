#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// A function To convert dec to bin
int decTo_bin_or_oct(int dec){
    int r,p,b;
    p =1 ;
    b = 0;
    while(dec!=0){
        r = dec % 2 ;
        b = b + r * p;
        p = p * 10;
        dec = (int)dec/2;
    }
    return b;
}
// main program
int main(){
    // opening a file
    FILE *text_file ;
    FILE *new_file ;
    // set reading mode
    text_file = fopen("text.txt","r");
    new_file = fopen("bin.txt","a");
    // reading the content of the file
    char ch;
    while ((ch = fgetc(text_file)) != EOF) {
        // EOF = the char isn't an ASCII value
        int CharBin = decTo_bin_or_oct(ch+0);
        char BinStr[7];
        char space = ' ';
        itoa(CharBin,BinStr,10);
        if (ch+0 !=27){
            strncat(BinStr,&space,1);
        }
        else{
            char newLine = '\n';
            strncat(BinStr,&newLine,1);
        }
        fprintf(new_file,BinStr,"\n");
    }
    // closing the file
    fclose(text_file);
    fclose(new_file);
    return 0;
}