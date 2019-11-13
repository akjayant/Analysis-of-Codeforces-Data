#include <iostream>
#include <vector>
#include <algorithm>

typedef long long i64;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> d(n);
  for (int i = 0; i < n; i++)
    std::cin >> d[i];
  std::sort(d.begin(), d.end());
  std::reverse(d.begin(), d.end());
  int i = 1;
  for (; i <= n; i++)
    if (d[i-1] < i)
      break;
  std::cout << (i-1) << "\n";
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