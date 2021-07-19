using System.Data.SqlTypes;

namespace kata
{
    public class Board
    {
        private int _maxX;
        private int _maxY;
        
        private bool[,] _data;
        
        public Board(int x, int y)
        {
            _maxX = x;
            _maxY = y;
            _data = new bool[x,y];
        }

        public int MaxX => _maxX;
        public int MaxY => _maxY;

        public bool this[int x, int y]
        {
            get
            {
                if (x < 0 || x >= _maxX)
                {
                    return false;
                }

                if (y < 0 || y >= _maxY)
                {
                    return false;
                }
                return _data[x, y];
            }
            set {
                if (x >= 0 && x < _maxX && y >= 0 && y < _maxY)
                    _data[x, y] = value;
            }
        }
    }
}