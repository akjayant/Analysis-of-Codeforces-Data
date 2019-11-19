#include <iostream>
#include <algorithm>

int n;
int firstStairs, lastStairs;

int solve() {

  if (firstStairs == n)
    return n;

  return std::max((lastStairs+1)*2, (n-firstStairs)*2);
}

int main() {
  int q;
  std::cin >> q;
  for (unsigned i = 0; i != q; ++i) {
    std::cin >> n;
    firstStairs = n;
    lastStairs = n;
    for (unsigned r = 0; r != n; ++r) {
      char s;
      std::cin >> s;
      if (s == '1') {
        if (firstStairs == n)
          firstStairs = r;          
		lastStairs = r;	
      }
    }
    std::cout << solve() << "\n";
  }
  return 0;
}
