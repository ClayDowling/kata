#include "../RomanNumeral.h"

#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace ::testing;

class RomanNumeralTest : public TestWithParam<tuple<int, const char*>> {
public:
    RomanNumeral roman;
};

class RomanTests {
public:
    static vector<tuple<int, const char*>> generate() {
        vector<tuple<int, const char*>> tcase;
        tcase.push_back(make_tuple(1, "I"));
        tcase.push_back(make_tuple(2, "II"));
        tcase.push_back(make_tuple(3, "III"));
        tcase.push_back(make_tuple(4, "IV"));
        tcase.push_back(make_tuple(5, "V"));
        tcase.push_back(make_tuple(7, "VII"));
        tcase.push_back(make_tuple(9, "IX"));
        tcase.push_back(make_tuple(10, "X"));
        tcase.push_back(make_tuple(14, "XIV"));
        tcase.push_back(make_tuple(19, "XIX"));
        tcase.push_back(make_tuple(20, "XX"));
        tcase.push_back(make_tuple(40, "XL"));
        tcase.push_back(make_tuple(49, "XLIX"));
        tcase.push_back(make_tuple(50, "L"));
        tcase.push_back(make_tuple(90, "XC"));
        tcase.push_back(make_tuple(99, "XCIX"));
        tcase.push_back(make_tuple(100, "C"));
        tcase.push_back(make_tuple(400, "CD"));
        tcase.push_back(make_tuple(499, "CDXCIX"));
        tcase.push_back(make_tuple(500, "D"));
        tcase.push_back(make_tuple(900, "CM"));
        tcase.push_back(make_tuple(949, "CMXLIX"));
        tcase.push_back(make_tuple(990, "CMXC"));
        tcase.push_back(make_tuple(999, "CMXCIX"));
        tcase.push_back(make_tuple(1000, "M"));
        tcase.push_back(make_tuple(3999, "MMMCMXCIX"));
        tcase.push_back(make_tuple(3888, "MMMDCCCLXXXVIII"));

        return tcase;
    }
};

TEST_P(RomanNumeralTest, intToRoman)
{
    int testValue;
    const char* expected;

    testValue = get<0>(GetParam());
    expected = get<1>(GetParam());

    ASSERT_THAT(roman.toRoman(testValue), StrEq(expected));
}

INSTANTIATE_TEST_CASE_P(RomanNumeralDigitsTest, RomanNumeralTest, ValuesIn(RomanTests::generate()));