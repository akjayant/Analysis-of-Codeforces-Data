#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int q; cin >> q;
  while(q > 0) {
    q--;
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<P> ans;
    bool cando = true;
    for(int i=0;i<n-2;++i) {
      if(s[i] == t[i]) continue;
      bool ok = false;
      for(int j=i+1;j<n;++j) {
        if(t[i] == t[j]) {
          swap(s[i], t[j]);
          ans.push_back({i, j});
          ok = true;
          break;
        }
      }
      if(ok) continue;
      for(int j=i+1;j<n;++j) {
        if(t[i] == s[j]) {
          if(j == n-1) {
            swap(s[j], t[n-2]);
            ans.push_back({j, n-2});
            swap(s[i], t[n-2]);
            ans.push_back({i, n-2});
          } else {
            swap(s[j], t[j+1]);
            ans.push_back({j, j+1});
            swap(s[i], t[j+1]);
            ans.push_back({i, j+1});
          }
          ok = true;
          break;
        }
      }
      if(ok) continue;
      cando = false;
      break;
    }
    if(!cando) {
      cout << "No" << endl;
      continue;
    }
    if(s[n-2] == s[n-1] && t[n-2] == t[n-1]) {
      ans.push_back({n-1, n-2});
    } else if(s[n-2] == t[n-1] && s[n-1] == t[n-2]) {
      ans.push_back({n-1, n-1});
      ans.push_back({n-1, n-2});
    } else if(!(s[n-2] == t[n-2] && s[n-1] == t[n-1])) {
      cout << "No" << endl;
      continue;
    }
    assert((int)(ans.size()) <= 2*n);
    cout << "Yes" << endl;
    cout << (int)(ans.size()) << endl;
    for(int i=0;i<(int)(ans.size());++i) {
      cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
  }
}
