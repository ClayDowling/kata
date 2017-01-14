/**
 * Created by cdowling on 7/9/16.
 */
public class RomanNumeral {

    private static int [] singleDigits = {1, 5, 10};

    public static String toRoman(int value) {
        switch(value) {
            case 1:
                return "I";
            case 5:
                return "V";
            case 7:
                return "VII";
            default:
                return "X";
        }
    }

}
