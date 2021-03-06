#ifndef BIGNUM_BIGNUM_INT_H
#define BIGNUM_BIGNUM_INT_H

#include <string>
#include "Byte.h"

using namespace std;

enum OutTypes
{
    BINARY,
    DECIMAL
};

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
    string MultiplyByTwo(int multiplicationCount);
    string &DecimalSum(string &left, string &right);

public:
    BigNum_Int();
    BigNum_Int(int size);
    BigNum_Int(const BigNum_Int &origNum);
    void SetNumber(string number);
    string GetNumber(OutTypes type);
    ~BigNum_Int();

    BigNum_Int &operator=(const BigNum_Int& rightNum);
    friend const BigNum_Int operator+(BigNum_Int &leftNum, BigNum_Int &rightNum);
    friend const BigNum_Int operator-(BigNum_Int &leftNum, BigNum_Int &rightNum);
};

#endif //BIGNUM_BIGNUM_INT_H
