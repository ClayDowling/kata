#include "../unit.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;


TEST(answer, life_theuniverse_and_everything)
{
    ASSERT_EQ(42, answer());
}