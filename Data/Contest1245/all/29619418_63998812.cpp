#include <cstdio>

int mdc(int a, int b) {
  if (a < b) return mdc(b, a);
  if (b == 0) return a;
  return mdc(b, a % b);
}

int main() {

  int cases;

  scanf("%d", &cases);

  while (cases--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (mdc(a, b) == 1) {
      printf("Finite\n");
    } else {
      printf("Infinite\n");
    }
  }

  return 0;
}
