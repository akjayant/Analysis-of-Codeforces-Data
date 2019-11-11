#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef long long i64;

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (std::gcd(a, b) == 1)
    std::cout << "Finite\n";
  else
    std::cout << "Infinite\n";
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
