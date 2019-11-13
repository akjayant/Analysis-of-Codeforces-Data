#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#ifdef ConanYu
#include "local.hpp"
#else
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

int a[333][333];

void Main() {
  int n; cin >> n;
  int cur = n * n;
  for(int i = 1; i <= n; i++) {
    if(i % 2 == 0) {
      for(int j = 1; j <= n; j++) {
        a[j][i] = cur--;
      }
    } else {
      for(int j = n; j >= 1; j--) {
        a[j][i] = cur--;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << a[i][j] << " \n"[j == n];
    }
  }
}
