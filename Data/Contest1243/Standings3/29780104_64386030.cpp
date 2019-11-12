#include <iostream>
#include <vector>
#include <algorithm>

typedef long long i64;

#define CARD 256

void solve() {
  int n;
  std::cin >> n;
  std::string s, t;
  std::cin >> s >> t;

  int cs[CARD] = {0};
  for (int i = 0; i < n; i++) {
    cs[s[i]]++;
    cs[t[i]]++;
  }
  
  for (int i = 0; i < CARD; i++)
    if (cs[i] & 1) {
      std::cout << "No\n";
      return;
    }
  std::vector<std::pair<int, int>> exchanges;
  for (int i = 0; i < n; i++) {
    char want = s[i];
    if (want == t[i])
      continue;
    for (int j = i + 1; j < n; j++) {
      if (s[j] == want) {
        std::swap(t[i], s[j]);
        exchanges.push_back({j, i});
        break;
      } else if (t[j] == want) {
        std::swap(t[j], s[j]);
        std::swap(t[i], s[j]);
        exchanges.push_back({j, j});
        exchanges.push_back({j, i});
        break;
      }
    }
  }
  std::cout << "Yes\n";
  std::cout << exchanges.size() << "\n";
  for (auto& p : exchanges)
    ++p.first;
  for (auto& p : exchanges)
    ++p.second;
  for (auto p : exchanges)
    std::cout << p.first << ' ' << p.second << '\n';
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