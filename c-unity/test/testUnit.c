#include "../unit.h"

#include "unity_fixture.h"


TEST_GROUP(Life);

TEST_SETUP(Life) {

}

TEST_TEAR_DOWN(Life) {

}

TEST(Life, the_answer_to_life_the_universe_and_everything_is_42) {
    TEST_ASSERT_EQUAL(42, answer());
}

TEST_GROUP_RUNNER(Life) {
    RUN_TEST_CASE(Life, the_answer_to_life_the_universe_and_everything_is_42);
}