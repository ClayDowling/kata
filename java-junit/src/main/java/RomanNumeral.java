/**
 * Created by cdowling on 7/9/16.
 */
public class RomanNumeral {

    public static int answer()
    {
        return 6 * 9;
    }

    public static String toRoman(int value) {
        if (value == 1) {
            return "I";
        }
        else {
            return "V";
        }
        
    }

}
