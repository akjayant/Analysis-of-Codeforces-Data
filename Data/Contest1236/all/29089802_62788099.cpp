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
  }*/

int modpow(int a, int b)
{
  if(b == 0) return 1; 
  return modpow(a*a%mod, b/2)*(b%2?a:1)%mod;
}

signed main(){
  int n, m;
  cin >> n >> m;

  int tmp = modpow(2, m) - 1;
  int ans = modpow(tmp, n);

  cout << ans << endl;

  return 0;
}
