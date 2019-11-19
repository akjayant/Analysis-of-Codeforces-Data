#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 500 + 10;
int n, res, ans, pos[2]; char str[maxn], tmp[maxn];

int main(int argc, char const *argv[])
{
  scanf("%d", &n), scanf("%s", str + 1);
  ans = -1;
  for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) {
    for(int t = 1; t <= n; ++t) tmp[t] = str[t];
    swap(tmp[i], tmp[j]);
    int poi = 1, lim = n, top = 0;
    while( poi <= lim ) {
      if( tmp[poi] == ')' ) {
        if( top > 0 ) --top;
        else {
          --top, res = 0;
          while( poi <= lim && top < 0 ) {
            if( tmp[lim] == ')' ) --top, --lim;
            else ++top, --lim;
          }
        }
      }
      else ++top;
      ++poi;
      if( top == 0 ) ++res;
    }
    if( top ) res = 0;
    if( res > ans ) pos[0] = i, pos[1] = j, ans = res;
    res = 0;

  }
  printf("%d\n", ans);
  printf("%d %d\n", pos[0], pos[1]);

  return 0;
}