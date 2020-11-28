/* 
 * CS:APP Data Lab 
 * 
 * <muxv sjj12690303@gmail.com>
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
     * use combination of ~ and & to get different parts between bits
     */
    int all_one = x & y;
    int all_zero = ~x & ~y;
    return ~all_zero & ~all_one;
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    /*
     * use left shift from 00...01 to 10...0
     * 1 << 31
     */
    return (1 << 31);

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
     * use Tmax ability to pos overflow
     * and exclude the case x = -1
     */
    int if_minus_one = x + 1;  // -1      : 1 | others : 0
    int if_valid = x + x + 2; //  -1,Tmax : 1 | others : 0
    // -1        1                1
    // TMAX      1                0
    // Others    0

    return !(if_valid | !if_minus_one);
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
    /*
     * create a mask of 101010...10
     *
     */
    int odd_8 = 0xaa; // 10101010
    int odd_16 = (odd_8 << 8) | odd_8;
    int odd_32 = (odd_16 << 16) | odd_16;

    return !((x & odd_32) ^ odd_32);

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return 1 + ~x;
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
    /*
     * 0x30~0x37 -> 110 xxx
     * 0x38      -> 111 000
     * 0x39      -> 111 001
     */
    int equal38 = !(x ^ 0x38);            // 1 means equal 0x38
    int equal39 = !(x ^ 0x39);            // 1 means equal 0x39
    int equalOthers =  !((x >> 3) ^ 0x6); // 1 means equal[0x30, 0x37]
    return equal38 | equal39 | equalOthers;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /*flag     A    B  | func
     * 0  ->  -1    0  | -1
     * 1  ->   0   -1  | negate
     * return A&y + B&z
     *
     */
    int minus_one = ~1 + 1;
    int x_flag = !x;  // if x == 0 x_flag == 1
    int y_choose = (x_flag + minus_one) & y; //
    int z_choose = (~x_flag + 1) & z;        //

    return y_choose + z_choose;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /*
     * 1. when x and y is not the same sign
     * 1 & (y ^ x >> 31) gets sign difference
     *
     *
     * 2. when x and y is the same sign (include 0)
     * y - x >= 0
     * !((y - x >> 31) & 1)
     *
     */
    // 1. diff sign
    int diff_sign = 1 & ((y ^ x) >> 31); // diff sign 1; same sign 0
    // sign x ->  1(neg)  means x always <= y, return 1
    // sign x ->  0(pos)  means x always >  y, return 0
    int x_sign = 1 & (x >> 31);
    // 2. same sign
    int minus_x = ~x + 1;
    int sum = y + minus_x;
    int minus_sign = !(1 & (sum >> 31)); // <0 : 1 >= 0
    return (diff_sign & x_sign) + ((!diff_sign) & minus_sign);
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
     *
     * using negate and get sign-bit to create number 1
     * only 0 and Tmin when negating equal themselves
     * compare the ~x and their sign
     *          ~x_sign    ~minus_x_sign    &
     * 0        1          1                1
     * Tmin     0          0                0
     * others   1          0                0
     * others   0          1                0
     *
     */
    int minus_x = ~x + 1;
    int reverse_and_sign = 1 & ((~x & ~minus_x) >> 31);
    return reverse_and_sign;
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
    /*
     * x has the same bit of ~x(~x = -x-1)
     * use ~ to turn all x to positive
     * check the non-zero y == x >> n(in [0, 31])
     *      if y != 0 then res ++
     *      if y == 0 then res remain
     */

    // x ^ x_sign means
    // if x >= 0, x remain
    // else     , ~x
    int x_sign = x >> 31; // 111.11 or 000..00
    int abs_x = x ^ x_sign;

    int gt16 = !(!(abs_x >> 16)); // if > 16 -> 1 / else 0
    int part16 = gt16 << 4;  // << 4 == * 16
    int abs_x_16 = abs_x >> (16 & part16);// if part16==16, then only see high 16

    int gt8 = !!(abs_x_16 >> 8);
    int part8 = gt8 << 3;
    int abs_x_8 = abs_x_16 >> (8 & part8);

    int gt4= !!(abs_x_8 >> 4);
    int part4 = gt4 << 2;
    int abs_x_4 = abs_x_8 >> (4 & part4);

    int gt2= !!(abs_x_4 >> 2);
    int part2 = gt2 << 1;
    int abs_x_2 = abs_x_4 >> (2 & part2);

    int gt1= !!(abs_x_2 >> 1);
    int part1 = gt1;
    int abs_x_1 = abs_x_2 >> (1 & part1);

    int part0 = !!abs_x_1;



    int sum = part16 + part8 + part4 + part2 + part1 + part0 + 1;
    return sum;
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
    /*
     * add 1 on the exp and deal with special cases
     * deal with Inf and denorm
     *
     */
    unsigned sign = 1 & (uf >> 31);  //
    unsigned exp = 0xff & (uf >> 23);
    unsigned flac = (uf << 9) >> 9;
    unsigned res = 0;
    if (exp == 255) return uf;
    else if (exp == 0) flac = flac << 1;
    else exp += 1;

    res |= (sign << 31);
    res |= (exp << 23);
    res |= flac;

    return res;

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
    /*
     * deal with different exp (255, < 127, )
     */
    unsigned sign = 1 & (uf >> 31);
    unsigned exp = 0xff & (uf >> 23);
    unsigned flac = (uf << 9) >> 9;
    int E = exp - 127;   // times of right shift
    int norm = (flac | (1 << 23));
    int res = 0;

//    2^(exp-127) * 1.000000*******
//    1 000 0010 0000 0000 0000 0000 1111 1111
//    020000ff
    if (exp == 255) return 0x80000000u;
    else if (E < 0) return 0; // -127~ -1
    else if (E <= 23) // 0
    {         // implied 1
        res = norm >> (23 - E);
    }
    else if (E <= 30) // 0 ~ 127+30
    {
        res = norm << (E - 23);
    }
    // overflow all values are assigned to TMin regardless of its sign
    else return 1<<31;// > 127 + 30


    if (sign == 0) res = res;
    else res *= -1;
    return res;
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
    /*
     * norm   1.xxxx * 2^[-126, 127]   <= 10.0^127
     * denorm 0.xxxx * 2^-126
     *  numeber  rep
     * 2.0^ 128  0 1111 1111 (1)00..00 inf
     * 2.0^ 127  0 1111 1110 (1)00..00
     * 2.0^ 126  0 1111 1011 (1)00..00
     * ------------------------
     * 2.0^-126  0 0000 0001 (1)00..00 norm
     * -----denorm--------
     * 2.0^-127  0 0000 0000 (0)10..00 bit at 22
     * 2.0^-128  0 0000 0000 (0)01..00 bit at 21
     * ....
     * 2.0^-149  0.0000 0000 (0)00..01 bit at 0
     * 2.0^-150  0.0000 0000 (0)00..00 too small
     */
    unsigned pos_inf = 0xff << 23;
    // inf
    if (x >= 128) return pos_inf;
    // norm
    else if (x >= -126) return (x + 127) << 23;
    // denorm
    else if (x >= -149) return 1 << (x + 149);
    // too small
    else return 0;

}
