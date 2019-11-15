#include <bits/stdc++.h>
using namespace std;

int main() {
  int ka; scanf("%d", &ka);
  for(int i = 0; i < ka; i++) {
    int x, y; scanf("%d%d", &x, &y);
    printf("%s\n", __gcd(x, y) == 1 ? "Finite": "Infinite");
  }
  return 0;
}
