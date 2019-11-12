#include <cstdio>

using namespace std;

int a[1'009];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = n; i >= 1; --i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (a[j] >= i) {
          ++cnt;
        }
      }
      if (cnt >= i) {
        printf("%d\n", i);
        break;
      }
    }
  }
}
