// Play every game like it's my last.
// Created: Sun Oct 20 17:38:28 CST 2019
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
using namespace std;
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#define scd(X)    scanf("%d", &(X))
#define scdd(X,Y) scanf("%d%d", &(X), &(Y))
#define sc3d(X,Y,Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define sc4d(A,B,C,D) scanf("%d%d%d%d", &(A), &(B), &(C), &(D))
#define pb        push_back
#define mp        std::make_pair
const int INF     = 0x3f3f3f3f;
const double EPS  = 1e-11;
const LL mod = 1000000007LL;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  LL n, m;
  std::vector<LL> head(1000005);
  head[1] = 2;
  head[2] = 4;
  for (int i = 3; i <= 100000; ++i)
    head[i] = (head[i-1] + head[i-2]) % mod;

  while ( std::cin >> n >> m ) {
    LL x = head[m];
    if (n == 1) {
      std::cout << x << std::endl;
    } else if (n == 2) {
      std::cout << x + 2 << std::endl;
    } else {
      x += 2LL;
      for (int i = 1; i <= n-2; ++i) {
        x = (x + head[i]) % mod;
      }
      std::cout << x << std::endl;
    }
  }
  return 0;
}
