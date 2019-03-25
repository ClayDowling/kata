public class Game {

    public boolean rules(int neighbors, boolean live) {
        if (neighbors < 2 || neighbors >= 4) {
            return false;
        }
        if (live == false) {
            if (neighbors == 3) {
                return true;
            }
            return false;


        }
        return true;
    }
}
