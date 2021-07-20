using FluentAssertions;
using kata;
using Xunit;

namespace katatest
{
    public class GameTest
    {
        [Fact]
        public void Neighbors_WithNoLiveNeighbors_Returns0()
        {
            Board b = new Board(3, 3);

            Game.Neighbors(b, 1, 1).Should().Be(0);
        }

        [Fact]
        public void Neighbors_WithOneLiveNeighbor_Returns1()
        {
            Board b = new Board(3, 3);
            b[0, 0] = true;
            
            Game.Neighbors(b, 1, 1).Should().Be(1);
        }

        [Fact]
        public void Neighbors_WithLiveCellAndEightNeighbors_Returns8()
        {
            Board b = new Board(3, 3);
            for (int x = 0; x < b.MaxX; x++)
            {
                for (int y = 0; y < b.MaxY; y++)
                {
                    b[x, y] = true;
                }
            }

            Game.Neighbors(b, 1, 1).Should().Be(8);
        }

        [Theory]
        [InlineData(0, true)]
        [InlineData(1, true)]
        [InlineData(0, false)]
        [InlineData(1, false)]
        public void IsAlive_DuringUnderPopulation_ReturnsFalse(int neighbors, bool state)
        {
            Game.IsAlive(neighbors, state).Should().BeFalse();
        }

        [Theory]
        [InlineData(2)]
        [InlineData(3)]
        public void IsAlive_LiveCellWithTwoOrThreeNeighbors_ReturnsTrue(int neighbors)
        {
            Game.IsAlive(neighbors, true).Should().BeTrue();
        }

        [Fact]
        public void IsAlive_DeadCellWithTwoNeighbors_ReturnsFalse()
        {
            Game.IsAlive(2, false).Should().BeFalse();
        }

        [Fact]
        public void IsAlive_DeadOrLiveCellWithThreeNeighbors_ReturnsTrue()
        {
            Game.IsAlive(3, true).Should().BeTrue();
            Game.IsAlive(3, false).Should().BeTrue();
        }

        [Theory]
        [InlineData(4)]
        [InlineData(5)]
        [InlineData(6)]
        [InlineData(7)]
        [InlineData(8)]
        public void IsAlive_WhenOverpopulated_ReturnsFalse(int neighbors)
        {
            Game.IsAlive(neighbors, true).Should().BeFalse();
            Game.IsAlive(neighbors, false).Should().BeFalse();
        }
    }
}