using kata;
using Xunit;
using System;

namespace katatest
{
    public class testLife
    {

        [Fact]
        public void answer_byDefault_returns42()
        {
            Assert.Equal(42, LifeTheUniverseAndEverything.answer());
        }

    };
}