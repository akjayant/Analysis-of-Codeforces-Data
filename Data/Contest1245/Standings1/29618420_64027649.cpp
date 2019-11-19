#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define pd pair<double, double>
#define vp vector<pi>
#define f(i, n) for(int i = 0; i < n; i++)
#define fo(i, a, n) for(int i = a; i < n; i++)
#define mod (1000*1000*1000+7)
#define sz(x) int((x).size())
#define all(x) x.begin(),x.end()
#define DBG(v) cerr << #v << " = " << (v) << endl;
ll INF = (1ll<<61);

using namespace std;

string L, R;

ll dp[32][2][2][2][2];

ll d(int i, int j, int k, int l, int m){
  if(i == -1) return 1;
  if(dp[i][j][k][l][m] != -1) return dp[i][j][k][l][m];
  ll ans = 0;
  if(L[i] == '0' && R[i] == '0'){
    ans += d(i-1, j, k, l, m);
    if(m) ans += d(i-1, j, k, 1, m);
    if(k) ans += d(i-1, 1, k, l, m);
  }else if(L[i] == '0' && R[i] == '1'){
    ans += d(i-1, j, 1, l, 1);
    ans += d(i-1, j, 1, 1, m);
    ans += d(i-1, 1, k, l, 1);
  }else if(L[i] == '1' && R[i] == '0'){
    if(j && l) ans += d(i-1, j, k, l, m);
    if(j && m) ans += d(i-1, j, k, l, m);
    if(k && l) ans += d(i-1, j, k, l, m);
  }else if(L[i] == '1' && R[i] == '1'){
    if(j && l) ans += d(i-1, j, 1, l, 1);
    if(j) ans += d(i-1, j, 1, l, m);
    if(l) ans += d(i-1, j, k, l, 1);
  }
  return dp[i][j][k][l][m] = ans;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
      f(i, 32) f(j, 2) f(k, 2) f(l, 2) f(m, 2) dp[i][j][k][l][m] = -1;
      ll l, r; cin >> l >> r;
      L.resize(32); R.resize(32);
      f(i, 32){
        L[i] = '0' + (l&1);
        R[i] = '0' + (r&1);
        l /= 2;
        r /= 2;
      }
      cout << d(31, 0, 0, 0, 0) << endl;
    }
    return 0;
}
