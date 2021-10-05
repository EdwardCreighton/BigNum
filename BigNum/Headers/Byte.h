#ifndef BIGNUM_BYTE_H
#define BIGNUM_BYTE_H

class Byte
{
private:
    char singleByte;

public:
    Byte();
    void SetBitCondition(int bitPosition, bool newCondition);
    void InverseByte();
    bool GetBitCondition(int bitPosition);
};

#endif //BIGNUM_BYTE_H
