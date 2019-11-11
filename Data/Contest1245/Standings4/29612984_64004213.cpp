#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long i64;

void solve() {
  int n, cr, cp, cs;
  std::cin >> n >> cr >> cp >> cs;
  std::string v;
  std::cin >> v;
  int score = 0;
  std::string ans;
  for (int i = 0; i < n; i++)
    ans += '-';
  std::fill(ans.begin(), ans.end(), '-');
  for (int i = 0; i < n; i++) {
    if (v[i] == 'S' && cr) {
      cr--;
      ans[i] = 'R';
      score++;
    }
    if (v[i] == 'P' && cs) {
      cs--;
      ans[i] = 'S';
      score++;
    }
    if (v[i] == 'R' && cp) {
      cp--;
      ans[i] = 'P';
      score++;
    }
  }
  if (score >= (n+1)/2) {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (ans[i] == '-') {
        if (cs) {
          ans[i] = 'S';
          cs--;
        } else if (cr) {
          ans[i] = 'R';
          cr--;
        } else {
          ans[i] = 'P';
          cp--;
        }
      }
    }
    std::cout << ans << "\n";
  } else {
    std::cout << "NO\n";
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int t;
  std::cin >> t;
  while (t--)
    solve();

  return 0;
}
