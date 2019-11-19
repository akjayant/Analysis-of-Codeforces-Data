#include <iostream>

int main() {

  int q; 
  int a,b,c,d,k;
  
  std::cin >> q;
  
  for (unsigned i = 0; i != q; ++i) {

    std::cin >> a >> b >> c >> d >> k;
  
    int x = a / c + ((a % c) ? 1 : 0);
    int y = b / d + ((b % d) ? 1 : 0);
  
    if (x + y > k) {
      std::cout << "-1\n";
    } else
      std::cout << x << " " << y << "\n";
  }
  
  return 0;
}