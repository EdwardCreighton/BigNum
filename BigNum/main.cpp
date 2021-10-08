#include <iostream>
#include "Headers/BigNum_Int.h"

using namespace std;

int main()
{
    BigNum_Int number1;
    number1.SetNumber("16");

    BigNum_Int number2(1);
    number2.SetNumber("10");

    BigNum_Int number3;

    number3 = number2 - number1;

    cout << number3.GetNumber(OutTypes(BINARY)) << endl;
}
