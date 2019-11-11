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
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    string s; cin >> s;

    map<char, vector<int>> mp;
    for(int i=0; i<n; i++) {
      mp[s[i]].push_back(i);
    }

    string res = string(n, '?');
    int wins = 0;
    for(int x : mp['R']) {
      if(b == 0) break;
      res[x] = 'P';
      b--;
      wins++;
    }
    for(int x : mp['P']) {
      if(c == 0) break;
      res[x] = 'S';
      c--;
      wins++;
    }
    for(int x : mp['S']) {
      if(a == 0) break;
      res[x] = 'R';
      a--;
      wins++;
    }

    string r = "";
    while(a) { r += "R"; a--; }
    while(b) { r += "P"; b--; }
    while(c) { r += "S"; c--; }

    for(int i=0; i<n; i++) {
      if(res[i] == '?') {
        res[i] = r.back();
        r.pop_back();
      }
    }

    if(wins >= (n+1)/2) {
      cout << "Yes" << endl;
      cout << res << endl;
    }
    else cout << "No" << endl;

  }

  return 0;
}
