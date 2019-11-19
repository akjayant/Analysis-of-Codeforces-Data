///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair< int, pair<int, int> >
#define plpll pair< ll, pair<ll, ll> >

using namespace std;

const int maxn = 1000* 100 + 5, mod = 1000* 1000* 1000 + 7;
int dp[maxn];

int32_t main(){
      int n, m;
      cin >>n >>m;
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i <= max(n, m); i ++)
            dp[i] = (dp[i - 1] + dp[i - 2])% mod;
      cout <<((dp[n]+ dp[m] - 1)* 2)% mod <<endl;
      return false;
}
