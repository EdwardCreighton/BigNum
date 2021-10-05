#ifndef BIGNUM_BIGNUM_INT_H
#define BIGNUM_BIGNUM_INT_H

#include <string>
#include "Byte.h"

using namespace std;

class BigNum_Int
{
private:
    Byte* p_number;
    int size;
    bool isNegative;

    bool CheckIfEven(char lastDigit);
    string DivideByTwo(string numerator);
    int TransformCharToInt(char character);
    char TransformIntToChar(int integer);
    void SetNewSize(int newSize);

public:
    BigNum_Int();
    BigNum_Int(int size);
    BigNum_Int(const BigNum_Int &origNum);
    void SetNumber(string number);
    ~BigNum_Int();

    BigNum_Int &operator=(const BigNum_Int& rightNum);
    friend const BigNum_Int operator+(BigNum_Int &leftNum, BigNum_Int &rightNum);
    friend const BigNum_Int operator-(BigNum_Int &leftNum, BigNum_Int &rightNum);
};

#endif //BIGNUM_BIGNUM_INT_H
