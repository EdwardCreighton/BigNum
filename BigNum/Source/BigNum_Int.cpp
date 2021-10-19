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

    if (number[0] == '-')
    {
        isNegative = true;

        string temp;

        for (int i = 1; i < number.length(); ++i)
        {
            temp += number[i];
        }

        number = temp;
    }

    while (number != "1")
    {
        isEven = CheckIfEven(number[number.size() - 1]);

        number = DivideByTwo(number);

        if (byteCount >= size)
        {
            Byte* temp = new Byte[size + 1];

            for (byteCount = 0; byteCount < size; ++byteCount)
            {
                temp[byteCount] = p_number[byteCount];
            }

            delete[] p_number;

            p_number = temp;

            ++size;
        }

        p_number[byteCount].SetBitCondition(bitCount, !isEven);

        ++bitCount;

        if (bitCount == 8)
        {
            bitCount = 0;
            ++byteCount;
        }
    }

    if (byteCount >= size)
    {
        Byte* temp = new Byte[size + 1];

        for (byteCount = 0; byteCount < size; ++byteCount)
        {
            temp[byteCount] = p_number[byteCount];
        }

        delete[] p_number;

        p_number = temp;

        ++size;
    }

    p_number[byteCount].SetBitCondition(bitCount, true);

    if (isNegative)
    {
        for (byteCount = 0; byteCount < size; ++byteCount)
        {
            p_number[byteCount].InverseByte();
        }

        bool digitTransfer = true;

        for (byteCount = 0; byteCount < size; ++byteCount)
        {
            for (bitCount = 0; bitCount < 8; ++ bitCount)
            {
                if (digitTransfer)
                {
                    if (p_number[byteCount].GetBitCondition(bitCount))
                    {
                        p_number[byteCount].SetBitCondition(bitCount, false);
                    }
                    else
                    {
                        p_number[byteCount].SetBitCondition(bitCount, true);
                        digitTransfer = false;
                    }
                }

                if (!digitTransfer) break;
            }

            if (!digitTransfer) break;
        }
    }
}

string BigNum_Int::GetNumber(OutTypes type)
{
    string outNumber;

    int byteCount;
    int bitCount;

    if (type == OutTypes(BINARY))
    {
        for (byteCount = size - 1; byteCount >= 0; --byteCount)
        {
            for (bitCount = 7; bitCount >= 0; --bitCount)
            {
                if (p_number[byteCount].GetBitCondition(bitCount))
                {
                    outNumber += '1';
                }
                else
                {
                    outNumber += '0';
                }
            }
        }
    }
    else if (type == OutTypes(DECIMAL))
    {
        if (isNegative)
        {
            for (byteCount = 0; byteCount < size; ++byteCount)
            {
                p_number[byteCount].InverseByte();
            }

            bool digitTransfer = true;

            for (byteCount = 0; byteCount < size; ++byteCount)
            {
                for (bitCount = 0; bitCount < 8; ++ bitCount)
                {
                    if (digitTransfer)
                    {
                        if (p_number[byteCount].GetBitCondition(bitCount))
                        {
                            p_number[byteCount].SetBitCondition(bitCount, false);
                        }
                        else
                        {
                            p_number[byteCount].SetBitCondition(bitCount, true);
                            digitTransfer = false;
                        }
                    }

                    if (!digitTransfer) break;
                }

                if (!digitTransfer) break;
            }
        }

        int digitCount = 0;
        outNumber = "0";

        for (byteCount = 0; byteCount < size; ++byteCount)
        {
            for (bitCount = 0; bitCount < 8; ++ bitCount)
            {
                if (p_number[byteCount].GetBitCondition(bitCount))
                {
                    string temp = MultiplyByTwo(digitCount);
                    outNumber = DecimalSum(outNumber, temp);
                }

                ++digitCount;
            }
        }

        string temp;

        if (isNegative)
        {
            temp += '-';
        }

        for (int i = outNumber.size() - 1; i >= 0; --i)
        {
            temp += outNumber[i];
        }

        outNumber = temp;
    }

    return outNumber;
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

        if (!(chCount == 0 && dividedInteger == 0))
        {
            dividedNumber += TransformIntToChar(dividedInteger);
        }
    }

    return dividedNumber;
}

int BigNum_Int::TransformCharToInt(char character)
{
    switch (character)
    {
        case '0':
        {
            return 0;
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

string BigNum_Int::MultiplyByTwo(int multiplicationCount)
{
    if (multiplicationCount == 0)
    {
        return "1";
    }

    string outString = "2";
    bool digitTransfer = false;

    for (int counter = 1; counter < multiplicationCount; ++counter)
    {
        for (int j = 0; j < outString.size(); ++j)
        {
            int currentDigit = TransformCharToInt(outString[j]);

            currentDigit *= 2;

            if (digitTransfer)
            {
                ++currentDigit;
            }

            digitTransfer = bool(currentDigit / 10);

            char newDigit = TransformIntToChar(currentDigit % 10);

            outString[j] = newDigit;
        }

        if (digitTransfer)
        {
            outString += '1';
            digitTransfer = false;
        }
    }

    return outString;
}

string &BigNum_Int::DecimalSum(string &left, string &right)
{
    string *minValue;
    string *maxValue;

    int minSize;
    int maxSize;

    bool digitTransfer = false;

    if (left.size() > right.size())
    {
        minValue = &right;
        maxValue = &left;

        minSize = right.size();
        maxSize = left.size();
    }
    else
    {
        minValue = &left;
        maxValue = &right;

        minSize = left.size();
        maxSize = right.size();
    }

    int digitCount;

    for (digitCount = 0; digitCount < minSize; ++digitCount)
    {
        int maxValueDigit = TransformCharToInt((*maxValue)[digitCount]);
        int minValueDigit = TransformCharToInt((*minValue)[digitCount]);

        maxValueDigit += minValueDigit;

        if (digitTransfer)
        {
            ++maxValueDigit;
        }

        digitTransfer = bool(maxValueDigit / 10);

        (*maxValue)[digitCount] = TransformIntToChar(maxValueDigit % 10);
    }
    for (digitCount = minSize; digitCount < maxSize; ++digitCount)
    {
        if (digitTransfer)
        {
            int maxValueDigit = TransformCharToInt((*maxValue)[digitCount]);

            ++maxValueDigit;

            digitTransfer = bool(maxValueDigit / 10);

            (*maxValue)[digitCount] = TransformIntToChar(maxValueDigit % 10);
        }
        else
        {
            break;
        }
    }

    if (digitTransfer)
    {
        *maxValue += '1';
        digitTransfer = false;
    }

    return *maxValue;
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

    this->isNegative = rightNum.isNegative;

    return *this;
}

const BigNum_Int operator+(BigNum_Int &leftNum, BigNum_Int &rightNum)
{
    bool rightNumberBigger;
    int maxSize;
    int minSize;

    int byteCount;
    int bitCount;

    BigNum_Int resultBigNum;

    if (!leftNum.isNegative && !rightNum.isNegative)
    {
        if (leftNum.size > rightNum.size)
        {
            maxSize = leftNum.size;
            minSize = rightNum.size;
            rightNumberBigger = false;
            resultBigNum.SetNewSize(maxSize);
        }
        else if (leftNum.size < rightNum.size)
        {
            maxSize = rightNum.size;
            minSize = leftNum.size;
            rightNumberBigger = true;
            resultBigNum.SetNewSize(maxSize);
        }
        else
        {
            maxSize = leftNum.size;
            minSize = leftNum.size;
            rightNumberBigger = true;
            resultBigNum.SetNewSize(maxSize + 1);
        }
    }
    else if (!leftNum.isNegative && rightNum.isNegative)
    {
        BigNum_Int temp;
        temp = rightNum;

        for (byteCount = 0; byteCount < temp.size; ++byteCount)
        {
            temp.p_number[byteCount].InverseByte();
        }

        bool digitTransfer = true;

        for (byteCount = 0; byteCount < temp.size; ++byteCount)
        {
            for (bitCount = 0; bitCount < 8; ++bitCount)
            {
                if (digitTransfer)
                {
                    if (temp.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        temp.p_number[byteCount].SetBitCondition(bitCount, false);
                    }
                    else
                    {
                        temp.p_number[byteCount].SetBitCondition(bitCount, true);
                        digitTransfer = false;
                    }
                }

                if (!digitTransfer) break;
            }

            if (!digitTransfer) break;
        }

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
            maxSize = rightNum.size;
            minSize = rightNum.size;
        }

        bool stopIterating = false;

        for (byteCount = maxSize - 1; byteCount >= minSize; --byteCount)
        {
            for (bitCount = 7; bitCount >= 0; --bitCount)
            {
                if (!stopIterating)
                {
                    if (byteCount <= temp.size && temp.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = true;
                        stopIterating = true;
                    }
                    else if (byteCount <= leftNum.size && leftNum.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = false;
                        stopIterating = true;
                    }
                }
                else
                {
                    break;
                }
            }

            if (stopIterating) break;
        }

        for (byteCount = minSize - 1; byteCount >= 0; --byteCount)
        {
            for (bitCount = 7; bitCount >= 0; --bitCount)
            {
                if (!stopIterating)
                {
                    if (temp.p_number[byteCount].GetBitCondition(bitCount) && !leftNum.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = true;
                        stopIterating = true;
                    }
                    else if (!temp.p_number[byteCount].GetBitCondition(bitCount) && leftNum.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = false;
                        stopIterating = true;
                    }
                }
                else
                {
                    break;
                }
            }

            if (stopIterating) break;
        }

        if (!rightNumberBigger)
        {
            resultBigNum.SetNewSize(leftNum.size);
        }
        else
        {
            resultBigNum.SetNewSize(rightNum.size);
            resultBigNum.isNegative = true;
        }
    }
    else if (leftNum.isNegative && !rightNum.isNegative)
    {
        BigNum_Int temp;
        temp = leftNum;

        for (byteCount = 0; byteCount < temp.size; ++byteCount)
        {
            temp.p_number[byteCount].InverseByte();
        }

        bool digitTransfer = true;

        for (byteCount = 0; byteCount < temp.size; ++byteCount)
        {
            for (bitCount = 0; bitCount < 8; ++bitCount)
            {
                if (digitTransfer)
                {
                    if (temp.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        temp.p_number[byteCount].SetBitCondition(bitCount, false);
                    }
                    else
                    {
                        temp.p_number[byteCount].SetBitCondition(bitCount, true);
                        digitTransfer = false;
                    }
                }

                if (!digitTransfer) break;

            }

            if (!digitTransfer) break;
        }

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
            maxSize = rightNum.size;
            minSize = rightNum.size;
        }

        bool stopIterating = false;

        for (byteCount = maxSize - 1; byteCount >= minSize; --byteCount)
        {
            for (bitCount = 7; bitCount >= 0; --bitCount)
            {
                if (!stopIterating)
                {
                    if (byteCount <= temp.size && temp.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = false;
                        stopIterating = true;
                    }
                    else if (byteCount <= rightNum.size && rightNum.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = true;
                        stopIterating = true;
                    }
                }
                else
                {
                    break;
                }
            }

            if (stopIterating) break;
        }

        for (byteCount = minSize - 1; byteCount >= 0; --byteCount)
        {
            for (bitCount = 7; bitCount >= 0; --bitCount)
            {
                if (!stopIterating)
                {
                    if (temp.p_number[byteCount].GetBitCondition(bitCount) && !rightNum.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = false;
                        stopIterating = true;
                    }
                    else if (!temp.p_number[byteCount].GetBitCondition(bitCount) && rightNum.p_number[byteCount].GetBitCondition(bitCount))
                    {
                        rightNumberBigger = true;
                        stopIterating = true;
                    }
                }
                else
                {
                    break;
                }
            }

            if (stopIterating) break;
        }

        if (rightNumberBigger)
        {
            resultBigNum.SetNewSize(rightNum.size);
        }
        else
        {
            resultBigNum.SetNewSize(leftNum.size);
            resultBigNum.isNegative = true;
        }
    }
    else if (leftNum.isNegative && rightNum.isNegative)
    {
        if (leftNum.size > rightNum.size)
        {
            maxSize = leftNum.size;
            minSize = rightNum.size;
            rightNumberBigger = false;
        }
        else if (leftNum.size < rightNum.size)
        {
            maxSize = rightNum.size;
            minSize = leftNum.size;
            rightNumberBigger = true;
        }
        else
        {
            maxSize = leftNum.size;
            minSize = leftNum.size;
            rightNumberBigger = true;
        }

        resultBigNum.SetNewSize(maxSize + 1);
    }

    bool digitTransfer = false;

    for (byteCount = 0; byteCount < minSize; ++byteCount)
    {
        for (bitCount = 0; bitCount < 8; ++bitCount)
        {
            if (leftNum.p_number[byteCount].GetBitCondition(bitCount) && rightNum.p_number[byteCount].GetBitCondition(bitCount))
            {
                if (digitTransfer)
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                }
                else
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                    digitTransfer = true;
                }
            }
            else if (leftNum.p_number[byteCount].GetBitCondition(bitCount) && !rightNum.p_number[byteCount].GetBitCondition(bitCount))
            {
                if (digitTransfer)
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                }
                else
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                }
            }
            else if (!leftNum.p_number[byteCount].GetBitCondition(bitCount) && rightNum.p_number[byteCount].GetBitCondition(bitCount))
            {
                if (digitTransfer)
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                }
                else
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                }
            }
            else if (!leftNum.p_number[byteCount].GetBitCondition(bitCount) && !rightNum.p_number[byteCount].GetBitCondition(bitCount))
            {
                if (digitTransfer)
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                    digitTransfer = false;
                }
                else
                {
                    resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                }
            }
        }
    }

    for (byteCount = minSize; byteCount < maxSize; ++byteCount)
    {
        for (bitCount = 0; bitCount < 8; ++bitCount)
        {
            if (rightNumberBigger)
            {
                if (rightNum.p_number[byteCount].GetBitCondition(bitCount))
                {
                    if (digitTransfer)
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                        digitTransfer = false;
                    }
                    else
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                    }
                }
                else
                {
                    if (digitTransfer)
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                        digitTransfer = false;
                    }
                    else
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                    }
                }
            }
            else
            {
                if (leftNum.p_number[byteCount].GetBitCondition(bitCount))
                {
                    if (digitTransfer)
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                        digitTransfer = false;
                    }
                    else
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                    }
                }
                else
                {
                    if (digitTransfer)
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                        digitTransfer = false;
                    }
                    else
                    {
                        resultBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                    }
                }
            }
        }
    }

    return resultBigNum;
}

const BigNum_Int operator-(BigNum_Int &leftNum, BigNum_Int &rightNum)
{
    BigNum_Int tempBigNum(rightNum.size);
    tempBigNum = rightNum;

    int byteCount;

    for (byteCount = 0; byteCount < tempBigNum.size; ++byteCount)
    {
        tempBigNum.p_number[byteCount].InverseByte();
    }

    bool digitTransfer = true;

    for (byteCount = 0; byteCount < tempBigNum.size; ++byteCount)
    {
        for (int bitCount = 0; bitCount < 8; ++bitCount)
        {
            if (digitTransfer)
            {
                if (tempBigNum.p_number[byteCount].GetBitCondition(bitCount))
                {
                    tempBigNum.p_number[byteCount].SetBitCondition(bitCount, false);
                }
                else
                {
                    tempBigNum.p_number[byteCount].SetBitCondition(bitCount, true);
                    digitTransfer = false;
                }
            }

            if (!digitTransfer) break;

        }

        if (!digitTransfer) break;
    }

    tempBigNum.isNegative = !tempBigNum.isNegative;

    BigNum_Int resultBigNum;
    resultBigNum = leftNum + tempBigNum;

    return resultBigNum;
}
