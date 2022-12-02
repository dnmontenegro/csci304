/*
This program prints three lines. First line is an example of including a percentage sign. 
Second line prints two integers and their difference. Last line gives two floats and their quotient.
*/
#include <stdio.h>
#include <stdlib.h>
//Prints "One half is 50%"
void oneHalf(void)
{
  int value = 50;
  printf("One half is %d%%\n", value);
}
//prints two integers and their difference
void difference(void)
{
  int valueOne = 10;
  int valueTwo = 3;
  printf("The difference between %d and %d is %d\n", valueOne, valueTwo, valueOne - valueTwo);
}
//prints two floats and their quotient
void quotient(void)
{
  float valueOne = 1.0;
  float valueTwo  = 3.0;
  printf("%f / %f is %f\n", valueOne, valueTwo , valueOne / valueTwo );
}
int main(void)
{
  oneHalf();
  difference();
  quotient();
  return (EXIT_SUCCESS);
}
