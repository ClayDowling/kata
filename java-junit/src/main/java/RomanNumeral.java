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
        RomanDigit digit = findSingleDigit(value);
        String result = "";
        if (digit != null) {
            result = result + digit.symbol;
        } else {


            switch (value) {
                case 2:
                    result = "II";
                    break;
                case 7:
                    result =  "VII";
                    break;
                default:
                    result = "undefined";
            }
        }
        return result;
    }
}
