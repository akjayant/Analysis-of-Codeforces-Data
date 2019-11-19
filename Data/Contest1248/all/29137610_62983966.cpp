// Play every game like it's my last.
// Created: Sun Oct 20 17:17:51 CST 2019
#include <algorithm>
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
  int n;
  vector<int> a;
  while (scd(n) != EOF) {
    a.resize(n);
    for (int i = 0; i < n; ++i)
      scd(a[i]);
    sort( a.begin(), a.end() );
    LL sum = 0LL;
    LL lsum = 0LL;
    int mid = n >> 1;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (i < mid) lsum += a[i];
    }
    LL rsum = sum - lsum;
    std::cout << rsum * rsum + lsum * lsum << std::endl;
  }
  return 0;
}
