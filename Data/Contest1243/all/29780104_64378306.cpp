#include <iostream>
#include <vector>
#include <algorithm>

typedef long long i64;

void solve() {
  int n;
  std::cin >> n;
  std::string s, t;
  std::cin >> s >> t;

  std::vector<int> neq;
  for (int i = 0; i < n; i++)
    if (s[i] != t[i])
      neq.push_back(i);
  if (neq.size() == 2) {
    int a = neq[0], b = neq[1];
    std::swap(s[a], t[b]);
    if (s[a] == t[a] && s[b] == t[b])
      std::cout << "Yes\n";
    else
      std::cout << "No\n";
  } else
    std::cout << "No\n";
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int q;
  std::cin >> q;
  while (q--)
    solve();

  return 0;
}