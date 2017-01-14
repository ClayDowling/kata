#include <cstring>
#include "RomanNumeral.h"

static RomanDigit singleDigit[] = {
        {.value = 1, .symbol = "I"},
        {.value = 4, .symbol = "IV"},
        {.value = 5, .symbol = "V"},
        {.value = 9, .symbol = "IX"},
        {.value = 10, .symbol = "X"},
        {.value = 40, .symbol = "XL"},
        {.value = 50, .symbol = "L"}
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
