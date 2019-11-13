#include <cstdio>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int T, a, b;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &b);
    puts(gcd(a, b) == 1 ? "Finite" : "Infinite");
  }
  return 0;
}