#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ld dp[10][10];
ll ladder[10][10];

pair<ll, ll> advance(ll x, ll y, ll q) {
  for (ll i=0; i<q; ++i) {
    if (x==0 && (y&1)) {y++;}
    else if (x==9 && ((y&1)==0)) {y++;}
    else x+= (y&1) ? -1 : 1;
  }
  return {x, y};
}

ld r(ll x, ll y) {
  if (dp[x][y]!=-1) return dp[x][y];
  dp[x][y] = 1;
  for (ll i=1; i<=6; ++i) {
    auto q = advance(x, y, i);
    ll nx = q.first;
    ll ny= q.second;
    dp[x][y] += min(r(nx, ny), r(nx, ny+ladder[nx][ny]))*(1.l/6.l);
  }
  return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  for (ll i=0; i<10; ++i) {
    for (ll j=0; j<10; ++j) dp[i][j]=-1;
  }

  dp[0][9] = 0;
  dp[1][9] = 6;
  dp[2][9] = 6;
  dp[3][9] = 6;
  dp[4][9] = 6;
  dp[5][9] = 6;

  for (ll y=9; y>=0; --y) {
    for (ll x=0; x<10; ++x) {
      cin>>ladder[x][y];
    }
  }
  cout<<fixed<<setprecision(15)<<r(0, 0)<<endl;

}