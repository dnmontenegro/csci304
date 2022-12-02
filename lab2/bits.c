/* 
 * CS:APP Data Lab 
 * 
 * <David Montenegro, dnmontenegro>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*Left shifts to isolate the least significant bit, then right shifts to repeat the bit.*/
  return (x << 31) >> 31;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*shifts desired byte to the least significant byte position then returns its value by 
  using AND with a single byte of all ones*/
  return (x >> (n << 3)) & 0xff;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /*We check if the inputs match by using XOR. Since XOR returns 0 if equal and
  1 otherwise, we use ! to get the opposite value of the results of XOR.*/
  return !(x ^ y);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /*We first make a mask where there are 1s from highbit to 0 using a starting 
  mask of all 1s, right shifts, inversion. We then right shift up to 
  lowbit then left shift the same amount to convert all 1s after lowbit to 0.*/
  int mask = ~0;
  mask = ~(mask << (highbit)) | (1 << highbit);
  mask = (mask >> lowbit) << lowbit;
  return mask;
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /*Takes each chunk of 8 bits by using AND and a shifted 0xff literal and shifts them left 
  or right by a literal that is based on the fact that input is 32-bit integers. We use 
  OR to combine the result of these shifts.*/
  return ((x >> 24) & (0xff)) | ((x & (0xff << 16)) >> 8) | ((x & (0xff << 8)) << 8) | ((x & 0xff) << 24);
}

 /* bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*By using OR with x and -x (~x+1), we check if x is 0 or not. Then we right shift to
  repeat the most significant bit. We add 1 to get the correct return value.*/
  return ((x | (~x + 1)) >> 31) + 1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /*By using AND with x and -x (~x+1), we get the 1 bit in the same position between the
  two. This is the least significant 1 bit.*/
  return x & (~x + 1);
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  /*Inverts all bits in 0.*/
  return ~0;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /*Left shifts to isolate 1 as the most signifcant bit, then inverts all the bits.*/
  return ~(1 << 31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /*We right shift then left shift 32 - n times which should leave us n bits of x and then 
  store it in a new variable. Since the computer is uses two's complement, if x does not equal 
  shifted then x cannot be stored in n bits.*/
  int shifted = (x << (33 + ~n)) >> (33 + ~n);
  return !(shifted ^ x);
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /*Overflow is determined by the most signifigant bit (MSB). Therefore we right shift to 
  copy the MSB for all 32 bits for easy comparisons. We then know if there is overflow if 
  the MSB of x and y match but x + y does not.*/
  int sum = (x + y) >> 31;
  x = x >> 31;
  y = y >> 31;
  return ((x ^ y) | (!(sum ^ x) & !(sum ^ y))) & 1;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /*By using XOR we check if x and y have the same sign or not. By using OR we combine the
  results of XOR and (x + ~y), which checks if x-y is negative or not. By using AND we check 
  if y is negative and x is positive or 0. By using OR again, we combine the results of AND
  and the result of the previous OR.*/
  return ((y >> 31) & !(x >> 31)) | !(((x ^ y) >> 31) | ((x + ~y) >> 31));
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  /*We right shift to repeat the most significant bit (MSB), then using AND
  we check if the MSB is equal to 1 or not.*/
  return (x >> 31) & 1;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
  /* We use left and right shift to easily multiply by 5 and divide by 8. 
  Positive numbers round properly, so we only worry about negatives. We add 1 
  if remainder + ((x >> 31) & 7) leads to overflow because only a negative x can cause overflow.*/
  int remainder = x & 7;
  x = x + (x << 2);
  return (x >> 3) + (((((x >> 31) & 7) + remainder) >> 3) & 1);
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /*We need to know if the number is negative so we right shift to copy the MSB and 
  store it in negCheck. Either negCheck or its inversion will be all 1s. If we use an OR
  with negCheck we can decide to return just x or its conversion.*/
  int negCheck = x >> 31;
  return (~negCheck & x) | (negCheck & ((~x | 1 << 31) + 1));
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /*We left shift to isolate the sign bit as the MSB. We use a while loop that checks if (x&(1<<31)) 
  is 0. If it is then x is left shifted and the exponent is decreased by 1. We left shift to leave 
  room for the mantissa. By using AND with x and the max 2s compliment int, we right shift the 
  result to get the mantissa. The fraction is then correctly rounded if needed.*/
  int sign = (x >> 31) & 1;
  int exponent, fraction;
  if(!x)
    return 0;
  if(sign)
    x = ~x + 1;
  sign = sign << 31;
  exponent = 158;
  while(!(x & (1 << 31))) {
    x = x << 1;
    exponent = exponent + ~0;
  }
  exponent = exponent << 23;
  fraction = (x & ~(1 << 31)) >> 8;
  if(x & 128 && ((x & 127) > 0 || fraction & 1))
    fraction = fraction + 1;
  return sign + exponent + fraction;
}
