#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <unordered_map>

#define int ll
#define fs first
#define sd second
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define OUT(x) { cout << x; exit(0); }
//#define resize do_not_use_resize
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const db eps = 1e-9;
const db pi = acos(-1.0);
const db dinf = 1e250;
const ll INF = (ll)(2e18);
const int inf = (int)(1e18 + 7);
const int mod = 1e9 + 7;
//------------------------------------------//

vector<vector<ll>> a;



int32_t main()
{
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);


  //--------------------------------//
  
  int k; cin >> k;
  while (k--) {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int m = 0;
    bool fl = 0;
    vector<pair<char, char>> v;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[i]) continue;
      fl = 0;
      for (int j = i+1; j < n; ++j) {
        if (s[j] == s[i]) {
          s[j] = t[i];
          t[i] = s[i];
          v.pb({j, i});
          ++m;
          fl = 1;
          break;
        }
        if (t[j] == s[i]) {
          t[j] = s[j];
          s[j] = t[i];
          t[i] = s[i];
          v.pb({j, j});
          v.pb({j, i});
          m+=2;
          fl = 1;
          break;
        }
      }
      if (!fl) {
        cout << "No" << endl;
        break;
      }
    }
    if (fl) {
      cout << "Yes" << endl;
      cout << m << endl;
      for (int i = 0; i < m; ++i) {
        cout << v[i].first + 1 << ' ' << v[i].second + 1 << endl;
      }
    }
  }

  return 0;
}