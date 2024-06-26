/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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

#include <stdio.h>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/*
 * In the Xor, we can get the solution by using the following formula:
 * x bitXor y = (x & ~y) | (~x & y) = ~(~(x & ~y) & ~(~x & y))
 */

  int xor = ~(~(x & ~y) & ~(~x & y));
  
  return xor;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
/*
 * Construct the maximum number first, compare with the x.
 * If x is the maximum number, then the result will be 0.
 */

 int max = ~(1 << 31);
  int result = !(x ^ max);

  return result;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA;
  mask = (mask << 8) | mask;
  mask = (mask << 16) | mask;

  return !((x & mask) ^ mask);

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  int min = ~0;
  int y = ~x;
  int result = min + y +2;
  
  return result;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int lowerBound = x + ~0x30 + 1;
  int upperBound = 0x39 + ~x + 1;

  return !(lowerBound >> 31 | upperBound >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask = !!x;
  mask = ~mask + 1;
  return (mask & y) | (~mask & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
/*
 * Original version - Can't fix the bug
 int isLessOrEqual(int x, int y) {
printf("x: %d, y: %d\n", x, y);

int same = !(x ^ y);
printf("same: %d\n", same);

int div_x_y = x + ~y + 1; // x - y
printf("div_x_y: %d\n", div_x_y);
int sign_div_x_y = div_x_y >> 31 & 1; // sign of x - y, 1 means negative
printf("sign_div_x_y: %d\n", sign_div_x_y);

int div_y_x = y + ~x + 1; // y - x
printf("div_y_x: %d\n", div_y_x);
int sign_div_y_x = (div_y_x >> 31 & 1); // sign of y - x, 1 means negative
printf("sign_div_y_x: %d\n", sign_div_y_x);

printf("result: %d\n", same | sign_div_x_y | sign_div_y_x);

return same | (sign_div_x_y | sign_div_y_x);
}
 */
int isLessOrEqual(int x, int y) {
  //Got this answer from Google
  int y_sign = (y >> 31) & 1;
  int x_sign = (x >> 31) & 1;

  //check if x and ya re the same, whether one is negative or not, and check if x is less than y
  int z = (!(x_sign ^ y_sign)) & ((x + ~y) >> 31);

  return z | ((!y_sign) & x_sign);
}




//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*
   * Compare x and -x, if x is 0, then x and -x will be 0.
   */
  int result = ((x | (~x + 1)) >> 31) + 1;
  return result;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int flag;
  int bit_16, bit_8, bit_4, bit_2, bit_1;
  int sign = x >> 31;
  //printf("sign: %d\n", sign);
  x = (sign & ~x) | (~sign & x);
  //printf("x: %d\n", x);

  flag = !!(x >> 16);
  bit_16 = flag << 4;
  x = x >> bit_16;

  flag = !!(x >> 8);
  bit_8 = flag << 3;
  x = x >> bit_8;

  flag = !!(x >> 4);
  bit_4 = flag << 2;
  x = x >> bit_4;

  flag = !!(x >> 2);
  bit_2 = flag << 1;
  x = x >> bit_2;

  flag = !!(x >> 1);
  bit_1 = flag;
  x = x >> bit_1;


  return bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + x + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned int s, esp, frac;
  s = uf & 0x80000000;
  
  esp = uf & 0x7F800000;
  esp = esp >> 23;

  frac = uf & 0x007FFFFF;

  unsigned ret = 0;
  unsigned inf = s | (0xff << 23);

  if (esp == 0xff) return uf;

  if (esp == 0){
    if(frac == 0) return uf;

    frac = frac << 1;
    ret = s | (esp << 23) | frac;
    return ret;
  }

  esp++;

  if(esp == 0xff) return inf;

  ret = s | (esp << 23) | frac;

  return ret;


}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned int s, esp, frac;
  s = uf >> 31;

  
  esp = uf & 0x7F800000;
  esp = esp >> 23;

  frac = uf & 0x007FFFFF;

  int result = 0;

  int E = esp - 127;

  //printf("frac: %d\n", frac);
  frac = frac | 0x00800000;
  //printf("frac: %d\n", frac);
  /*
  Places a '1' at the 24th position from the right, which corresponds to the implicit '1' 
  that is always present in the mantissa of a normalized floating-point number but isn't included in the 23 bits stored in the frac.
   */

  if (E < 0) return 0;
  if (E > 31) return 0x80000000u;

  if (E > 23){
    result = frac << (E - 23);
  } else {
    result = frac >> (23 - E);
  }

  if(s == 1){
    return (~result) + 1;
  }else{
    return result;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int exp;
  unsigned ret;

  if(x < -149) return 0;//too small
  if(x > 127) return 0xff << 23;//too large

  if (x < -126) return 0x1 << (149 + x);
  exp = x + 127;
  ret = exp << 23;
  return ret;
}
