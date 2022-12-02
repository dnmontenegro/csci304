/*
This program does three things: 
Asks for two integers then gives the sum. 
Asks for two floats then gives the product. 
Asks for a string and prints the string twice.
*/
#include <stdio.h>
#include <stdlib.h>
//Asks for two integers then prints the sum.
void sum(void)
{
    int valueOne, valueTwo;
    printf("Give two integers: ");
    scanf("%d %d", &valueOne, &valueTwo);
    printf("You entered %d and %d, their sum is: %d\n", valueOne, valueTwo, valueOne + valueTwo);
}
//Asks for two floats then prints the product.
void product(void)
{
    float valueOne, valueTwo;
    printf("Give two floats: ");
    scanf("%f %f", &valueOne, &valueTwo);
    printf("You entered %f and %f, their product is: %f\n", valueOne, valueTwo, valueOne * valueTwo);
}
//Asks for a string then prints the string twice.
void twice(void)
{
    char word[100];
    printf("Give a word: ");
    scanf("%s", word);
    printf("%s %s\n", word, word);
}
int main(void)
{
    sum();
    product();
    twice();
    return (EXIT_SUCCESS);
}
