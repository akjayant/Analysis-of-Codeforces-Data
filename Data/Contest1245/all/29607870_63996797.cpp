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

void Main() {
  int t; cin >> t;
  while(t--) {
    int a, b; cin >> a >> b;
    int c = __gcd(a, b);
    if(c == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }
}
