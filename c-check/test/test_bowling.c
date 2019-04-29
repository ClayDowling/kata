#include "../bowling.h"
#include <check.h>

START_TEST(score_oneperframe_is10) {
  ck_assert_int_eq(score("1- 1- 1- 1- 1- 1- 1- 1- 1- 1-"), 10);
}
END_TEST

START_TEST(score_nineperframe_is90) {
  ck_assert_int_eq(score("9- 9- 9- 9- 9- 9- 9- 9- 9- 9-"), 90);
}
END_TEST

START_TEST(score_sparethenoneperframe_is20) {
  ck_assert_int_eq(score("1/ 1- 1- 1- 1- 1- 1- 1- 1- 1-"), 20);
}
END_TEST

START_TEST(score_strikethenoneperframe_is24) {
  ck_assert_int_eq(score("X 12 1- 1- 1- 1- 1- 1- 1- 1-"), 24);
}
END_TEST

START_TEST(score_perfectgame_is300) {
  ck_assert_int_eq(score("X X X X X X X X X XXX"), 300);
}
END_TEST

START_TEST(score_sixsparefivelastframe_is271) {
  ck_assert_int_eq(score("X X X X X X X X X 6/5"), 271);
}
END_TEST

TCase *tcase_bowling(void) {
  TCase *tc;

  tc = tcase_create("bowling");
  tcase_add_test(tc, score_oneperframe_is10);
  tcase_add_test(tc, score_nineperframe_is90);
  tcase_add_test(tc, score_sparethenoneperframe_is20);
  tcase_add_test(tc, score_strikethenoneperframe_is24);
  tcase_add_test(tc, score_perfectgame_is300);
  tcase_add_test(tc, score_sixsparefivelastframe_is271);

  return tc;
}

Suite *suite_bowling(void) {
  Suite *s;

  s = suite_create("alley");

  suite_add_tcase(s, tcase_bowling());

  return s;
}