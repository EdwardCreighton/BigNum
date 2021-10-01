#include "../Headers/BigNum_Int.h"

BigNum_Int::BigNum_Int()
{
    number = nullptr;
    size = 0;
    isNegative = false;
}

BigNum_Int::BigNum_Int(int size)
{
    number = new Byte[size];

    if (number == nullptr)
    {
        size = 0;
        isNegative = false;
        return;
    }

    this->size = size;
    isNegative = false;
}

BigNum_Int::~BigNum_Int()
{
    delete[] number;
}
