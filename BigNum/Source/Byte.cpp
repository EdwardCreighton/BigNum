#include "../Headers/Byte.h"

Byte::Byte()
{
    singleByte = 0;
}

void Byte::SetBitCondition(int bitPosition, bool newCondition)
{
    if (bitPosition > 7 || bitPosition < 0)
    {
        return;
        // TODO: Throw exception instead
    }

    if (newCondition)
    {
        singleByte |= (1 << bitPosition);
    }
    else
    {
        singleByte &= ~(1 << bitPosition);
    }
}

void Byte::InverseByte()
{
    for (int bitCount = 0; bitCount < 8; ++bitCount)
    {
        singleByte ^= (1 << bitCount);
    }
}

bool Byte::GetBitCondition(int bitPosition)
{
    if (bitPosition > 7 || bitPosition < 0)
    {
        return false;
        // TODO: Throw exception instead
    }

    if (singleByte & (1 << bitPosition))
    {
        return true;
    }

    return false;
}
