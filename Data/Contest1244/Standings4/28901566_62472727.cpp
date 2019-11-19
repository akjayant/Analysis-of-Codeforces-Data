// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define F first
#define S second
#define sz(x) ((int)x.size())
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, int >
#define E cout << '\n'

const int mod = 1e9 + 7;
const int N = 4e5 + 5;

// int a[N];
char s[N];
 
inline void solve() {
  int n;
  string st;
  cin >> n;
  int ans = n;
  cin >> (s+1);
  if (s[1] == '1' || s[n] == '1')
  	ans = n*2;
  else {
  	ans = n;
  	for (int i = 2; i < n; ++i) {
  		if (s[i] == '1') {
  			ans = max(ans, max(i*2, 2*(n-i+1)));
  		}
  	}
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t; while(t--)
  solve();
  return 0;
}