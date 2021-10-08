#include <iostream>
#include "Headers/BigNum_Int.h"

using namespace std;

int main()
{
    BigNum_Int number1(1);
    number1.SetNumber("10");

    BigNum_Int number2(1);
    number2.SetNumber("-16");

    BigNum_Int number3;

    number3 = number1 + number2;

    cout << number3.GetNumber(OutTypes(BINARY)) << endl;

    /*string str;
    char ch = '5';

    cout << "First call " + str << endl;

    str += ch;
    cout << "Second call " + str << endl;*/
}
