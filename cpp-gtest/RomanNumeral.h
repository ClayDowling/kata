#ifndef _ROMAN_NUMERAL_H_
#define _ROMAN_NUMERAL_H_


class RomanDigit {
public:
    int value;
    char symbol;
};

class RomanNumeral {
public:
char *toRoman(int value);
};

#endif