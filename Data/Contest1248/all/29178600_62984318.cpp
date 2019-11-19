#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt[2]; long long ans;

int main(int argc, char const *argv[])
{
  scanf("%d", &n);
  while( ~scanf("%d", &n) ) {
    cnt[0] = cnt[1] = 0, ans = 0;
    for(int x = 0, i = 1; i <= n; ++i) scanf("%d", &x), ++cnt[x & 1];
    scanf("%d", &m);
    for(int x = 0, i = 1; i <= m; ++i) scanf("%d", &x), ans = ans + cnt[x & 1];
    cout << ans << endl;
  }
  return 0;
}