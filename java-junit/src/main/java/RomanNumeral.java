/**
 * Created by cdowling on 7/9/16.
 */
public class RomanNumeral {

    private static RomanDigit [] singleDigits = new RomanDigit[] {
            new RomanDigit(1, "I"),
            new RomanDigit(5, "V"),
            new RomanDigit(10, "X")
    };

    private RomanDigit findSingleDigit(int digit) {
        for(RomanDigit roman : singleDigits ) {
            if (roman.value == digit) {
                return roman;
            }
        }
        return null;
    }

    public String toRoman(int value) {
        int index = singleDigits.length - 1;
        RomanDigit currentRoman;
        String result = "";

        while (value > 0) {
            currentRoman = singleDigits[index];

            if (currentRoman.value <= value) {
                value -= currentRoman.value;
                result += currentRoman.symbol;
            } else {
                index--;
            }
        }
        return result;
    }

}
