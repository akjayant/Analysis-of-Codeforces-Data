// Play every game like it's my last.
// Created: Sun Oct 20 17:10:02 CST 2019
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

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  int T;
  scd(T);
  while (T--) {
    int n, m;
    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));
    scd(n);
    for (int i = 0; i < n; ++i) {
      int x;
      scd(x);
      cnt[0][x%2] += 1;
    }
    scd(m);
    for (int i = 0; i < m; ++i) {
      int x;
      scd(x);
      cnt[1][x%2] += 1;
    }

    LL ret = 0LL;
    ret += 1LL * cnt[0][0] * cnt[1][0] + 1LL * cnt[0][1] * cnt[1][1];
    std::cout << ret << std::endl;
  }
  return 0;
}
