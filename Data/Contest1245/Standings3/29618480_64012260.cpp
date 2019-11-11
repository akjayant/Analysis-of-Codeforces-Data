#include <cstdio>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d%d", &a, &b);
    bool any = false;
    for (int i = 2; i <= a && i <= b; ++i) {
      if (a % i == 0 && b % i == 0) {
        any = true;
      }
    }
    puts(any ? "Infinite" : "Finite");
  }
}
