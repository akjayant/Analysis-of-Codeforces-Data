#include <iostream>
#include <vector>
#include <algorithm>

typedef long long i64;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  i64 n;
  std::cin >> n;
  for (i64 p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      i64 s = n;
      bool is_pow = true;
      while (s > 1) {
        if (s % p != 0) {
          is_pow = false;
          break;
        }
        s /= p;
      }
      if (is_pow)
        std::cout << p << std::endl;
      else
        std::cout << 1 << std::endl;
      return 0;
    }
  }
  std::cout << n << std::endl;

  return 0;
}