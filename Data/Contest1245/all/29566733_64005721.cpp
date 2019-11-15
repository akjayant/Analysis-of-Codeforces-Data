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
//#define int long long
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

char r[111];
signed main() {
  #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
      // freopen("out.txt", "w", stdout);
  #endif
  
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(10);
  int T;
  cin >> T;
  while(T--){
    fill(r, r + 110, '.');
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      if(s[i] == 'R' && b > 0) {
        --b;
        r[i] = 'P';
        ++cnt;
      } 
      if(s[i] == 'P' && c > 0) {
        --c;
        r[i] = 'S';
        ++cnt;
      }
      if(s[i] == 'S' && a > 0) {
        --a;
        r[i] = 'R';
        ++cnt;
      }
    }
    for(int i = 0; i < n; ++i) {
      if(r[i] == '.') {
        if(a > 0) {
          r[i] = 'R';
          --a;
        } else if(b > 0) {
          r[i] = 'P';
          --b;
        } else if(c > 0) {
          r[i] = 'S';
          --c;
        }
      }
    }
    r[n] = '\0';
    if(cnt >= (n + 1) / 2) {
      cout << "YES" << endl;
      cout << r << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}