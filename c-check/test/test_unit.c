#include "../unit.h"

#include <check.h>


START_TEST(the_answer_to_life_the_universe_and_everything)
{
    ck_assert_int_eq(answer(), 42);
}
END_TEST

TCase *tcase_life(void)
{
	TCase *tc;

	tc = tcase_create("life");
	tcase_add_test(tc, the_answer_to_life_the_universe_and_everything);

	return tc;
}

Suite *suite_life(void)
{
	Suite *s;

	s = suite_create("the-guide");

	suite_add_tcase(s, tcase_life());

	return s;
}

int main(int argc, char **argv)
{
	Suite *s;
	SRunner *runner;
	int number_fails;

	s = suite_life();
	runner = srunner_create(s);
	srunner_run_all(runner, CK_NORMAL);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}
