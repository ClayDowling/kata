#include <cstring>
#include "RomanNumeral.h"

static RomanDigit singleDigit[] = {
        {.value = 1, .symbol = "I"},
        {.value = 4, .symbol = "IV"},
        {.value = 5, .symbol = "V"},
        {.value = 9, .symbol = "IX"},
        {.value = 10, .symbol = "X"},
        {.value = 40, .symbol = "XL"},
        {.value = 50, .symbol = "L"},
        {.value = 90, .symbol = "XC"},
        {.value = 100, .symbol = "C"},
        {.value = 400, .symbol = "CD"},
        {.value = 500, .symbol = "D"},
        {.value = 900, .symbol = "CM"},
        {.value = 1000, .symbol = "M"}

};

string RomanNumeral::toRoman(int value) {
    string result = ""; // REDUNDANT
    int index = sizeof(singleDigit)/sizeof(RomanDigit) - 1;
    RomanDigit currentDigit = singleDigit[index];

    while(value > 0) {
        if (currentDigit.value <= value) {
            value -= currentDigit.value;
            result += currentDigit.symbol;
        } else {
            currentDigit = singleDigit[--index];
        }
    }
    return result;
}
