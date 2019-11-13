#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print() { cout << '\n'; }
template<class T> void print(const vector<T>& c) {
  for(const T &x : c) cout << x << ' ';
}
template<class T, class... Ts> void print(const T& t, const Ts&... ts) {
  cout << t; if (sizeof...(ts)) cout << ' '; print(ts...);
}

int main () {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  const int MOD = 1000000007;

  string s;
  while(cin >> s) {
    int n = s.size();

    if(count(s.begin(), s.end(), 'w')) {
      cout << 0 << endl;
      break;
    }
    if(count(s.begin(), s.end(), 'm')) {
      cout << 0 << endl;
      break;
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i=1; i<n; i++) {
      dp[i] += dp[i-1];
      if(s[i] == 'u' && s[i-1] == 'u') dp[i] += i>=2 ? dp[i-2] : 1;
      if(s[i] == 'n' && s[i-1] == 'n') dp[i] += i>=2 ? dp[i-2] : 1;
      dp[i] %= MOD;
    }

    cout << dp[n-1] << endl;
  }

  return 0;
}
