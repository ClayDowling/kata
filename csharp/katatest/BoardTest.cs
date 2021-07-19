using FluentAssertions;
using kata;
using Xunit;

namespace katatest
{
    public class BoardTest
    {
        [Fact]
        public void BoardDimensions_ByDefault_MatchConcstructor()
        {
            var actual = new Board(4,5);
            actual.MaxX.Should().Be(4);
            actual.MaxY.Should().Be(5);
        }

        [Fact]
        public void Indexer_GetsValue_PreviouslySet()
        {
            var actual = new Board(3, 3);
            actual[1, 1] = false;
            actual[1, 1].Should().BeFalse();

            actual[0, 0] = true;
            actual[0, 0].Should().BeTrue();
        }

        [Fact]
        public void Indexer_GetValueOutsideX_ReturnsFalse()
        {
            var actual = new Board(3, 3);
            actual[-1, 0] = true;
            actual[-1, 0].Should().BeFalse();

            actual[4, 0] = true;
            actual[4, 0].Should().BeFalse();
        }

        [Fact]
        public void Indexer_GetValueOutsideY_ReturnsFalse()
        {
            var actual = new Board(3, 3);
            actual[0, -1] = true;
            actual[0, -1].Should().BeFalse();

            actual[0, 4] = true;
            actual[0, 4].Should().BeFalse();
        }
    }
    
}