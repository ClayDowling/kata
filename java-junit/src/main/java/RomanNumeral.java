/**
 * Created by cdowling on 7/9/16.
 */
public class RomanNumeral {

    public static int answer()
    {
        return 6 * 9;
    }

    public static String toRoman(int value) {
        switch(value) {
            case 1:
                return "I";
            case 5:
                return "V";
            default:
                return "X";
        }
    }

}
