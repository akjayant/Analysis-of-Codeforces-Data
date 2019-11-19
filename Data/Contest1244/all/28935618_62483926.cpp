#include <iostream>
#include <cstdint>

uint64_t n, p, d, w;

void solve() {
  uint64_t v = p / w;
  if (v > n) {
    std::cout << "-1";
    return;
  }

  uint64_t rem = p % w;
  uint64_t di = d;  
  do {
    if (!(rem % d)) {
      uint64_t draws = rem / d;
      if (v + draws > n) {
        std::cout << "-1";
        return;      
      }
      uint64_t loses = n - draws - v;
      std::cout << v << " " << draws << " " << loses << "\n";
      return;
    }
    if (v) --v;
    --di;
    rem += w;
  } while (v && di);
  std::cout << "-1";  
}

int main() {
  std::cin >> n >> p >> w >> d;
  solve();
  return 0;  
}
