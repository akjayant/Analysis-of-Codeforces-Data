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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i=0; i < n; ++i) {
      if (i + 1 > a[i]) break;
      ++ans;
    }
    cout << ans << endl;
  }

  return 0;
}
