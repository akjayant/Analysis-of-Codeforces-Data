#include <iostream>

const long long BASE = 1000000007;

int n, m;

using namespace std;

long long Minus(long long x, long long y) {
  return (x - y + BASE) % BASE;
}

long long Power(long long a, long long b) {
  a = a % BASE;
  long long ans = 1;
  long long k = a;
  while (b > 0) {
    if (b % 2 == 1) {
      ans = ans * k % BASE;
    }
    b /= 2;
    k = k * k % BASE;
  }
  return ans;
}

int main() {
  cin >> n >> m;
  long long b = Power(2, m);
  b = Minus(b, 1);
  cout << Power(b, n) << endl;
  return 0;
}
