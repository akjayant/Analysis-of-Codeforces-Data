#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  1 4  
  2 3 

  1 6 7
  2 5 8
  3 4 9
  }*/

signed main(){
  int n;
  cin >> n;

  vvi ans(n, vi(n));
  rep(i, 0, n){
    rep(j, 0, n){
      (i%2 ? ans[n-j-1][i] : ans[j][i]) = i*n+j+1;
    }
  }

  rep(i, 0, n){
    rep(j, 0, n){
      cout << ans[i][j] << " \n"[j==n-1];
    }
  }

  return 0;
}
