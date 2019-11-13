#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define endl "\n"
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

ll dp[100100][3];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  ll n = s.sz;
  ll flag = 0;
  clr(dp,0);
  dp[0][0] = 1;
  rep(i,0,s.sz){
      if(s[i]=='w'||s[i]=='m')flag = 1;
      if(s[i]=='u'){
        dp[i+1][1] += dp[i][0]+dp[i][1]+dp[i][2];
        dp[i+1][0] += dp[i][1];
      }
      else if(s[i]=='n'){
        dp[i+1][2] += dp[i][0]+dp[i][1]+dp[i][2];
        dp[i+1][0] += dp[i][2];
      }
      else{
        dp[i+1][0] += dp[i][0];
        dp[i+1][0] += dp[i][1];
        dp[i+1][0] += dp[i][2];
      }
      dp[i+1][0] %= MOD;
      dp[i+1][1] %= MOD;
      dp[i+1][2] %= MOD;
  }
  if(flag == 1){
    cout << 0 << endl;
    return 0;
  }
  cout << (dp[n][0]+dp[n][1]+dp[n][2])%MOD << endl;
  return 0;
}