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
  int t; cin >> t;
  while(t > 0) {
    t--;
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    string s; cin >> s;
    int cntr = 0, cntp = 0, cnts = 0;
    for(int i=0;i<n;++i) {
      if(s[i] == 'R') {
        cntr++;
      } else if(s[i] == 'P') {
        cntp++;
      } else {
        cnts++;
      }
    }
    int ansr = min(a, cnts), ansp = min(b, cntr), anss = min(c, cntp);
    int need = n/2 + n%2;
    if(ansr + ansp + anss >= need) {
      cout << "YES" << endl;
      vector<char> ans(n, '0');
      for(int i=0;i<n;++i) {
        if(s[i] == 'R' && ansp > 0) {
          ans[i] = 'P';
          ansp--;
          b--;
        } else if(s[i] == 'P' && anss > 0) {
          ans[i] = 'S';
          anss--;
          c--;
        } else if(s[i] == 'S' && ansr > 0) {
          ans[i] = 'R';
          ansr--;
          a--;
        }
      }
      for(int i=0;i<n;++i) {
        if(ans[i] == '0') {
          if(a > 0) {
            ans[i] = 'R';
            a--;
          } else if(b > 0) {
            ans[i] = 'P';
            b--;
          } else {
            ans[i] = 'S';
            c--;
          }
        }
      }
      for(int i=0;i<n;++i) {
        cout << ans[i];
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
