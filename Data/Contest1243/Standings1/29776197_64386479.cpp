#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
vector< pair<int, int> > v;
int a[233];
char s[233];

int main (void) {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    mp.clear();
    v.clear();

    int n, c = 0;
    scanf("%d", &n);
    scanf("%s%s", s + 1, s + n + 1);
    for (int i = 1; i <= 2 * n; i++) {
      if (!mp[s[i]]) {
        a[i] = ++ c;
        mp[s[i]] = c;
      } else {
        a[i] = mp[s[i]];
        mp[s[i]] = 0;
      }
    }
    int ok = 1;
    for (auto & e : mp) {
      if (e.second) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      puts("No");
      continue;
    }
    for (int i = 1, j; i < n; i++) {
      int id = a[i];
      for (j = i + 1; j <= 2 * n; j++) {
        if (a[j] == id) break;
      }
      if (j <= n) {
        v.push_back({ j, i });
        swap(a[i + n], a[j]);
      } else {
        v.push_back({ n, j - n });
        swap(a[n], a[j]);
        v.push_back({ n, i });
        swap(a[n], a[i + n]);
      }
    }
    puts("Yes");
    printf("%d\n", v.size());
    for (auto & e : v) {
      printf("%d %d\n", e.first, e.second);
    }
  }
}