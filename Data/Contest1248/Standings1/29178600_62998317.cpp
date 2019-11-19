#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int mod = 1000000000 + 7;
int n, m, wxynb[maxn], dsrnb[maxn], orzxx, ans;

int main(int argc, char const *argv[])
{
  scanf("%d%d", &n, &m);

  for(int i = 0; i <= 1; ++i) wxynb[1 << i] = 1 << (i + 1);
  for(int i = 3; i <= n; ++i) wxynb[i] = (wxynb[i - 1] + wxynb[i - 2]) % mod;

  dsrnb[1] = 0, dsrnb[2] = 2;
  for(int i = 3; i <= m; ++i) dsrnb[i] = (dsrnb[i - 1] + dsrnb[i - 2]) % mod;

  for(int asdf = 1; asdf <= 1000; ++asdf) ;

  for(int i = 1; i <= m; ++i) orzxx = (orzxx + dsrnb[i]) % mod;
  printf("%d\n", (wxynb[n] + orzxx) % mod);

  return 0;
}