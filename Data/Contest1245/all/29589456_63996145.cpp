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

  int t; cin >> t;
  while(t--) {
    int x, y; cin >> x >> y;
    cout << (__gcd(x, y) != 1 ? "Infinite" : "Finite") << '\n';
  }

  return 0;
}
