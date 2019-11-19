/* monkukui 競技プログラミング用のテンプレート  (ここから) */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
using lnt = long long int;
using graph = vector<vector<int>>;
using wgraph = vector<vector<pair<int, long long int>>>;
long long int INF = 1001001001001001LL;
int inf = 100100100;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;
long long int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
long long int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
inline void yes(){ cout << "yes" << endl; }
inline void Yes(){ cout << "Yes" << endl; }
inline void YES(){ cout << "YES" << endl; }
inline void no(){ cout << "no" << endl; }
inline void No(){ cout << "No" << endl; }
inline void NO(){ cout << "NO" << endl; }
inline void possible(){ cout << "possible" << endl; }
inline void Possible(){ cout << "Possible" << endl; }
inline void POSSIBLE(){ cout << "POSSIBLE" << endl; }
inline void impossible(){ cout << "impossible" << endl; }
inline void Impossible(){ cout << "Impossible" << endl; }
inline void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for(int i = s; i < t; i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back

/* monkukui 競技プログラミング用のテンプレート (ここまで)*/

int main(){
  
  lint n, k; cin >> n >> k;
  vector<lint> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  
  if(a[0] == a[n - 1]) {
    cout << 0 << endl;
    return 0;
  } 

  lint i = 0;
  for(; a[i + 1] == a[i]; i++) {}
  lint j = n - 1;
  for(; a[j - 1] == a[j]; j--) {}

  while(k > 0) {
    lint leftWeight = i + 1;
    lint rightWeight = n - j;
    if(leftWeight <= rightWeight) {
      lint diff = a[i + 1] - a[i];
      lint total = leftWeight * diff;

      // 余裕
      if(total <= k) {
        k -= total;
        i++;
        if(i >= j) {
          cout << 0 << endl;
          return 0;
        }
        for(; a[i + 1] == a[i]; i++) {}
      } else {
        // 終わり
        lint ans = a[j] - a[i];
        ans -= k / leftWeight;
        cout << ans << endl;
        return 0;
      }
    }else{
      lint diff = a[j] - a[j - 1];
      lint total = rightWeight * diff;
      
      if(total <= k) {
        k -= total;
        j--;
        if(i >= j) {
          cout << 0 << endl;
          return 0;
        }
        for(; a[j - 1] == a[j]; j--) {}
      } else {
        lint ans = a[j] - a[i];
        ans -= k / rightWeight;
        cout << ans << endl;
        return 0;
      }
    }
  }
  
  cout << max(0LL, a[j] - a[i]) << endl;

  return 0;
}
