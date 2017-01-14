#include <cstring>
#include "RomanNumeral.h"

static RomanDigit singleDigit[] = {
        {.value = 1, .symbol = 'I'},
        {.value = 5, .symbol = 'V'},
        {.value = 10, .symbol = 'X'}
};

char *RomanNumeral::toRoman(int value) {
    int resultidx = 0;
    static char result[30];
    int index = sizeof(singleDigit)/sizeof(RomanDigit) - 1;
    RomanDigit currentDigit = singleDigit[index];

    memset(result, 0, sizeof(result));

    while(value > 0) {
        if (currentDigit.value <= value) {
            value -= currentDigit.value;
            result[resultidx++] = currentDigit.symbol;
        } else {
            currentDigit = singleDigit[--index];
        }
    }
    return result;
}
