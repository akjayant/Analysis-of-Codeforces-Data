#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

const int N = 59;

char s[N];
char t[N];
int cnt[26];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d%s%s", &n, s, t);
    for (int i = 0; i < 26; ++i) {
      cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      ++cnt[(int)(s[i] - 'a')];
      ++cnt[(int)(t[i] - 'a')];
    }
    bool ok = true;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2 == 1) {
        ok = false;
      }
    }
    if (!ok) {
      puts("No");
      continue;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[i]) {
        continue;
      }
      for (int j = i + 1; j < n; ++j) {
        if (s[j] == s[i]) {
          swap(s[j], t[i]);
          ans.emplace_back(j, i);
          break;
        }
        if (t[j] == s[i]) {
          swap(s[j], t[j]);
          swap(s[j], t[i]);
          ans.emplace_back(j, j);
          ans.emplace_back(j, i);
          break;
        }
      }
    }
    puts("Yes");
    printf("%d\n", (int)ans.size());
    for (auto &e : ans) {
      printf("%d %d\n", e.first + 1, e.second + 1);
    }
  }
}
