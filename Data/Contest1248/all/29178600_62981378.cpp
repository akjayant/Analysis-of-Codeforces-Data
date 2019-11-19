#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
int n, a[maxn]; long long l, w;

int main(int argc, char const *argv[])
{
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", a + i), w = w + a[i];
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n / 2; ++i) l = l + a[i];
  cout << l * l + (w - l) * (w - l) << "\n";

  return 0;
}