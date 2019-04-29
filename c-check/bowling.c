#include "bowling.h"
#include <stdlib.h>

#define MAX_ROLLS 24
#define STRIKE 'X'
#define SPARE '/'
#define GUTTER '-'
#define FRAME ' '

struct roll_t {
  int frame;
  int pins;
  char type;
};

int score(const char *game) {

  int roll = 0;
  int frame = 1;
  struct roll_t rolls[MAX_ROLLS];

  for (int i = 0; i < MAX_ROLLS; ++i) {
    rolls[i].pins = 0;
    rolls[i].type = ' ';
    rolls[i].frame = -1;
  }

  for (int i = 0; game[i] != '\0'; ++i) {
    switch (game[i]) {
    case FRAME:
      frame++;
      break;
    case GUTTER:
      rolls[roll].pins = 0;
      rolls[roll].frame = frame;
      ++roll;
      break;
    case '1':
      rolls[roll].pins = 1;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '2':
      rolls[roll].pins = 2;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '3':
      rolls[roll].pins = 3;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '4':
      rolls[roll].pins = 4;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '5':
      rolls[roll].pins = 5;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '6':
      rolls[roll].pins = 6;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '7':
      rolls[roll].pins = 7;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '8':
      rolls[roll].pins = 8;
      rolls[roll].frame = frame;
      roll++;
      break;
    case '9':
      rolls[roll].pins = 9;
      rolls[roll].frame = frame;
      roll++;
      break;
    case SPARE:
      rolls[roll].pins = 10 - rolls[roll - 1].pins;
      rolls[roll].type = SPARE;
      rolls[roll].frame = frame;
      roll++;
      break;
    case STRIKE:
      rolls[roll].pins = 10;
      rolls[roll].type = STRIKE;
      rolls[roll].frame = frame;
      roll++;
      break;
    }
  }

  int sum = 0;
  for (int i = 0; i < MAX_ROLLS; ++i) {
    if (rolls[i].type == SPARE) {
      if (rolls[i].frame != 10) {
        sum += rolls[i + 1].pins;
      }
    } else if (rolls[i].type == STRIKE) {
      if (rolls[i].frame != 10) {
        sum += rolls[i + 1].pins;
        sum += rolls[i + 2].pins;
      }
    }
    sum += rolls[i].pins;
  }

  return sum;
}