#include <cstdio>

using namespace std;

const int N = 10'009;

char s[N];
char t[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d%s%s", &n, s, t);
    int j = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        if (j == -1) {
          j = i;
        } else
        if (s[i] != s[j] || t[i] != t[j]) {
          cnt = 1'000'000'000;
        }
        ++cnt;
      }
    }
    puts(cnt == 2 ? "Yes" : "No");
  }
}
