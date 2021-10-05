#include "../Headers/BigNum_Int.h"

BigNum_Int::BigNum_Int()
{
    p_number = nullptr;
    size = 0;
    isNegative = false;
}

BigNum_Int::BigNum_Int(int size)
{
    p_number = new Byte[size];

    if (p_number == nullptr)
    {
        return;
        // TODO: Throw exception instead
    }

    this->size = size;
    isNegative = false;
}

BigNum_Int::BigNum_Int(const BigNum_Int &origNum)
{
    if (this->p_number != nullptr)
    {
        delete[] this->p_number;
    }

    this->p_number = new Byte[origNum.size];

    //TODO: Check memory allocation

    this->size = origNum.size;

    for (int i = 0; i < this->size; ++i)
    {
        this->p_number[i] = origNum.p_number[i];
    }
}

void BigNum_Int::SetNumber(string number)
{
    bool isEven = false;
    int byteCount = 0;
    int bitCount = 0;

    if (p_number == nullptr)
    {
        p_number = new Byte[4];

        if (p_number == nullptr)
        {
            return;
            // TODO: Throw exception instead
        }
    }

    // TODO: Check if allocated memory is enough for new number

    if (number[0] == '-')
    {
        isNegative = true;
    }

    do
    {
        isEven = CheckIfEven(number[number.size() - 1]);

        number = DivideByTwo(number);
        p_number[byteCount].SetBitCondition(bitCount, !isEven);

        ++bitCount;

        if (bitCount == 8)
        {
            bitCount = 0;
            ++byteCount;
        }
    } while (number != "1");

    if (isNegative)
    {
        byteCount = 0;

        for (byteCount; byteCount < size; ++byteCount)
        {
            p_number[byteCount].InverseByte();
        }

        // TODO: Add addition process
    }
}

BigNum_Int::~BigNum_Int()
{
    delete[] p_number;
}

bool BigNum_Int::CheckIfEven(char lastDigit)
{
    int integer;
    integer = TransformCharToInt(lastDigit);

    if (integer % 2 == 0)
    {
        return true;
    }

    return false;
}

string BigNum_Int::DivideByTwo(string numerator)
{
    int chCount = 0;
    int integer;
    int dividedInteger;
    bool addHalf = false;
    string dividedNumber;

    if (numerator == "1")
    {
        dividedNumber = "1";
        return dividedNumber;
    }

    for (chCount; chCount < numerator.size(); ++chCount)
    {
        integer = TransformCharToInt(numerator[chCount]);
        dividedInteger = integer / 2;

        if (addHalf)
        {
            dividedInteger += 5;
        }

        if (integer % 2 == 0)
        {
            addHalf = false;
        }
        else
        {
            addHalf = true;
        }

        dividedNumber[chCount] = TransformIntToChar(dividedInteger);
    }

    return dividedNumber;
}

int BigNum_Int::TransformCharToInt(char character)
{
    switch (character)
    {
        case '0':
        {
            return 1;
            break;
        }
        case '1':
        {
            return 1;
            break;
        }
        case '2':
        {
            return 2;
            break;
        }
        case '3':
        {
            return 3;
            break;
        }
        case '4':
        {
            return 4;
            break;
        }
        case '5':
        {
            return 5;
            break;
        }
        case '6':
        {
            return 6;
            break;
        }
        case '7':
        {
            return 7;
            break;
        }
        case '8':
        {
            return 8;
            break;
        }
        case '9':
        {
            return 9;
            break;
        }
    }
}

char BigNum_Int::TransformIntToChar(int integer)
{
    switch (integer)
    {
        case 0:
        {
            return '0';
            break;
        }
        case 1:
        {
            return '1';
            break;
        }
        case 2:
        {
            return '2';
            break;
        }
        case 3:
        {
            return '3';
            break;
        }
        case 4:
        {
            return '4';
            break;
        }
        case 5:
        {
            return '5';
            break;
        }
        case 6:
        {
            return '6';
            break;
        }
        case 7:
        {
            return '7';
            break;
        }
        case 8:
        {
            return '8';
            break;
        }
        case 9:
        {
            return '9';
            break;
        }
    }
}

void BigNum_Int::SetNewSize(int newSize)
{
    Byte* new_p_number = new Byte[newSize];

    for (int i = 0; i < this->size; ++i) {
        new_p_number[i] = this->p_number[i];
    }

    delete[] this->p_number;

    this->p_number = new_p_number;
    this->size = newSize;
}

BigNum_Int &BigNum_Int::operator=(const BigNum_Int &rightNum)
{
    if (this == &rightNum)
    {
        return *this;
    }

    if (this->p_number != nullptr)
    {
        delete[] this->p_number;
    }

    this->p_number = new Byte[rightNum.size];

    // TODO: Check memory allocation

    this->size = rightNum.size;

    for (int i = 0; i < this->size; ++i)
    {
        this->p_number[i] = rightNum.p_number[i];
    }

    return *this;
}

const BigNum_Int operator+(BigNum_Int &leftNum, BigNum_Int &rightNum)
{
    bool rightNumberBigger;
    int maxSize;
    int minSize;
    BigNum_Int resultBigNum;

    if (!leftNum.isNegative && !rightNum.isNegative)
    {
        if (leftNum.size > rightNum.size)
        {
            maxSize = leftNum.size;
            minSize = rightNum.size;
        }
        else if (leftNum.size < rightNum.size)
        {
            maxSize = rightNum.size;
            minSize = leftNum.size;
        }
        else
        {
            maxSize = leftNum.size;
            minSize = leftNum.size;
        }
    }
}

const BigNum_Int operator-(BigNum_Int &leftNum, BigNum_Int &rightNum)
{
    return BigNum_Int();
}

