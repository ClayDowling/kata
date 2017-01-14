#ifndef _ROMAN_NUMERAL_H_
#define _ROMAN_NUMERAL_H_

#include <string>


using namespace std;

class RomanDigit {
public:
    int value;
    string symbol;
};

class RomanNumeral {
public:
string toRoman(int value);
};

#endif