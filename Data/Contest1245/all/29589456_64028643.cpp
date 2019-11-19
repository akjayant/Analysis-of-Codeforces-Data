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

  int n = 10;
  vector<int> lad(n*n, -1);

  auto xy2id = [&](int r, int c) {
    if(r%2) return r*n + (n-1-c);
    else return r*n + c;
  };

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int t; cin >> t;
      if(t) lad[xy2id(i,j)] = xy2id(i-t,j);
    }
  }

  vector<double> dp(n*n, 0.0);
  for(int i=1; i<n*n; i++) {
    if(i <= 6) {
      double k = i/6.0;
      double s = 1;
      for(int j=1; j<=i; j++) s += 1.0/6.0 * dp[i-j];
      s *= 1.0/k;
      dp[i] = s;
    }
    else {
      double s = 0;
      for(int j=1; j<=6; j++) {
        if(lad[i-j] != -1) {
          s += min(dp[lad[i-j]], dp[i-j]);
        }
        else {
          s += dp[i-j];
        }
      }
      dp[i] = 1.0/6.0 * s + 1.0;
    }
  }

  cout << fixed;
  cout.precision(9);
  cout << dp.back() << endl;

  return 0;
}
