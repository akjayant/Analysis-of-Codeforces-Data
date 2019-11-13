#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
//__int128


signed main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(10);
  string s;
  cin >> s;
  int n = (int)s.size();
  std::vector<int> f(n + 10);
  f[0] = f[1] = 1;
  for(int i = 2; i <= n; ++i) {
    f[i] = (f[i - 1] + f[i - 2]) % M;
  }
  int res = 1;
  for(int i = 0; i < n; ++i) {
    if(s[i] == 'm' || s[i] == 'w') {
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i = 0; i < n; ) {
    int c = 1, j = i + 1;
    if(s[i] == 'u' || s[i] == 'n') {
      while(s[j] == s[i]) {
        ++c;
        ++j;
      }
    }
    res = res * f[c] % M;
    i = j;
  }
  cout << res << endl;
  return 0;
}