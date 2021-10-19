#include <iostream>
#include "Headers/BigNum_Int.h"

using namespace std;

int main()
{
    BigNum_Int number1;
    string str1;
    cout << "Enter first number: ";
    cin >> str1;
    number1.SetNumber(str1);

    cout << "\nNumber 1: " << number1.GetNumber(OutTypes(BINARY)) << endl;
    cout << "Number 1: " << number1.GetNumber(OutTypes(DECIMAL)) << endl;

    BigNum_Int number2(1);
    string str2;
    cout << "\nEnter second number: ";
    cin >> str2;
    number2.SetNumber(str2);

    cout << "\nNumber 2: " << number2.GetNumber(OutTypes(BINARY)) << endl;
    cout << "Number 2: " << number2.GetNumber(OutTypes(DECIMAL)) << endl;


    BigNum_Int number3 = number1 - number2;

    cout << "\nNumber 3: " << number3.GetNumber(OutTypes(BINARY)) << endl;
    cout << "Number3: " << number3.GetNumber(OutTypes(DECIMAL)) << endl;
}
