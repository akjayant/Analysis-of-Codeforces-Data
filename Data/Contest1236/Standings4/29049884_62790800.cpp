#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add_self(int &x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
}

void sub_self(int &x, int y) {
  x -= y;
  if (x < 0)
    x += mod;
}

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0)
    x += mod;
  return x;
}

int powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for( ; b; b >>= 1){
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
  }
  return res % mod;
}

int mult(int x, int y) {
  return (1LL * x * y) % mod;
}

int divide(int x, int y) {
  return mult(x, powmod(y, mod - 2));
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", powmod(sub(powmod(2, m), 1), n));
  return 0;
}