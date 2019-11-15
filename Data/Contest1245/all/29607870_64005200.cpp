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

char S[105];

void Main() {
  int t;
  cin >> t;
  while(t--) {
    int n; cin >> n;
    memset(S, 0, sizeof(*S) * (n + 1));
    int a, b, c; cin >> a >> b >> c;
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'R' && b) {
        S[i] = 'P';
        b--;
      } else if(s[i] == 'P' && c) {
        S[i] = 'S';
        c--;
      } else if(s[i] == 'S' && a) {
        S[i] = 'R';
        a--;
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(!S[i]) {
        if(a) {
          S[i] = 'R';
          a--;
        } else if(b) {
          S[i] = 'P';
          b--;
        } else {
          S[i] = 'S';
          c--;
        }
      } else {
        ans++;
      }
    }
    if(ans >= (n + 1) / 2) {
      cout << "YES\n";
      cout << S << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
