#include <stdio.h>

int check(int x) {
  int y;
  if (x > 0) {
    y = 1;
  } else {
    y = 0;
  } 
  return y;
}

int main() {
  int result;
  result = check(2147483648);
  return result;
}
