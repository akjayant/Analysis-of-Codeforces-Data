#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define repChar(i) for (char i = 'a'; i <= 'z'; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs; cin >> tcs;
  rep(tc,0,tcs) {
    int n; cin >> n;
    string s; cin >> s;

    bool allZero = true;
    trav(c,s) if (c != '0') allZero = false;
    if (allZero) {
      cout << n << endl;
      continue;
    }

    int a = 0;
    rep(i,0,n) {
      if (s[i] == '1') {
        a = i + 1;
      }
    }
    int b = 0;
    rep(i,0,n) {
      if (s[i] == '1') {
        b = i;
        break;
      }
    }

    cout << max(2 * a, 2 * (n - b)) << endl;
  }
}
