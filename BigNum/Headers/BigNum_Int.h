#ifndef BIGNUM_BIGNUM_INT_H
#define BIGNUM_BIGNUM_INT_H

#include "../Headers/Byte.h"

class BigNum_Int
{
private:
    Byte* number;
    int size;
    bool isNegative;

public:
    BigNum_Int();
    BigNum_Int(int size);

    void SetNumber(char* newNumber);

    ~BigNum_Int();
};

#endif //BIGNUM_BIGNUM_INT_H
