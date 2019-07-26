// https://images.xiaozhuanlan.com/photo/2018/d1152250355a9cc0dd07216314ee8bdd.png

// https://images.xiaozhuanlan.com/photo/2018/e43ab2299026d0250cc5fdb68ca076e0.png

// 請 google: fsm valid number
bool isNumber(char *s) {
  int FSM[5][9] = {{1, -1, 9, -1, 9, -1, -1, 9, 9},
                   {2, -1, -1, -1, -1, 7, -1, -1, -1},
                   {3, 3, 3, 5, 5, 8, 8, 8, -1},
                   {4, 4, 5, -1, -1, -1, -1, -1, -1},
                   {-1, -1, 6, -1, 6, -1, -1, -1, -1}};

  if (s == nullptr) {
    return false;
  }

  int curState = 1;

  while ('\0' != *s) {

    int input = 0;
    char c = *(s++);

    if ('0' <= c && '9' >= c) {
      input = 2;
    } else if (' ' == c) {
      input = 0;
    } else if ('.' == c) {
      input = 3;
    } else if ('+' == c || '-' == c) {
      input = 1;
    } else if ('e' == c) {
      input = 4;
    } else {
      input = -1;
    }

    if (!(0 <= input && 5 >= input)) {
      return false;
    }

    curState = FSM[input][curState - 1];

    if (-1 == curState) {
      return false;
    }
  }

  if (curState == 3 || curState == 5 || curState == 8 || curState == 9) {
    return true;
  } else {
    return false;
  }
}