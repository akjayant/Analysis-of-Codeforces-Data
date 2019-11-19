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
  if (n > m)
    swap(n, m);
  const int N = 3e5 + 10;
  vector<int> c(N, 2), r(N, 2);
  for (int i = 3; i < N; ++i)
    c[i] = add(c[i - 1], c[i - 2]);
  r[2] = r[3] = 4;
  for (int i = 4; i < N; ++i)
    r[i] = add(r[i - 1], r[i - 2]);
  for (int i = 2; i < N; ++i)
    r[i] = add(r[i], r[i - 1]);
  int start = r[n];
  int p = n;
  int delta = m - n;
  while (delta--)
    start = add(start, c[p++]);
  printf("%d\n", start);
  return 0;
}