#include <iostream>

using namespace std;

const long long M = 1000000007;

long long n, m;

long long Calc(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  long long r = Calc(x, n / 2);
  r = (r * r) % M;
  if ((n & 1) == 1) {
    r = (r * x) % M;
  }
  return r;
}

int main() {
  cin >> n >> m;
  long long tmp = (Calc(2, m) + M - 1) % M;
  cout << Calc(tmp, n) << endl;
  return 0;
}