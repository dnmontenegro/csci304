/*
Reads a txt file. Each line will have all its characters turned into uppercase and the characters in the 
words will be reversed. Underscores will be changed to spaces. Words are considered any alphanumeric sequence 
seperated by non alphanumeric characters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//swaps values given two pointers
void swapPointer(char *px, char *py)
{
    char temp = *px;
    *px = *py;
    *py = temp;
}
//changes all characters in a string to uppercase
void uppercase(char* upper) 
{
    while(*upper) {
        *upper = toupper(*upper);
        upper++;
    }
}
//swaps characters in a string between two indices: start and end
void swap(int start, int end, char* buff) 
{
    while(start < end) {
        end--;
        swapPointer(buff+start, buff+end);
        start++;
    }
}
/*
Reverses the characters of each word while keeping nonalphabetic characters in their original position.
Makes all alphabetic characters uppercase and replaces underscores with spaces.
*/
void reverse(char* buff, FILE *fpout)
{
    uppercase(buff); //make string all uppercase
    int x = 0;
    int last = x;
    //loop through each character in string
    while(x < strlen(buff)){
        //check if current character is alphabetical
        if(!isalpha(*(buff+x))){
            //replace underscore with space
            if(*(buff+x) == '_'){
                *(buff+x) = ' ';
            }
            //reverse word that came before current nonalphabetical character
            swap(last, x, buff);
            last = x+1;
        }
        x++;
    }
    swap(last, x, buff); //reverse word that comes at end of string
    //output result to file
    fputs(buff, fpout);
    fputs("\n", fpout);
}
int main(void)
{
    FILE *fpin, *fpout;
    fpin = fopen("lab1p3in.txt","r");
    fpout = fopen("lab1p3out.txt","w");
    char buff[100] = {'0'};
    while(fgets(buff, 100, fpin)) {
        reverse(buff, fpout);
    }
    fclose(fpin);
    fclose(fpout);
    return (EXIT_SUCCESS);
}
