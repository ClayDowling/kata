namespace kata
{
    public class Game
    {
        public static int Neighbors(Board board, int x, int y)
        {
            int live = 0;
            for (int i = 0; i < board.MaxX; i++)
            {
                for (int j = 0; j < board.MaxY; j++)
                {
                    if (board[i, j] && !(i == x && j == y)) live++;
                }
            }
            return live;
        }

        public static bool IsAlive(int neighbors, bool cellstate)
        {
            switch (neighbors)
            {
                case 0:
                case 1:
                    return false;
                default:
                    return true;
            }
        }
    }
}