#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<ll, ll>;
using P3 = pair<ll, P>;
using PP = pair<P ,P>;
constexpr ll MOD = ll(1e9+7);
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

ll power(ll x, ll n){
    ll res = 1;
    x %= MOD;
    while(n > 0){
        if(n & 1){
            res = res*x%MOD;
        }
        x = x*x%MOD;
        n >>= 1;
    }
    return res;
}

ll dp[MAX_N][4];

int main(){
    ll n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    dp[0][3] = 1;
    for(int i=0;i<max(m,n);i++){
        for(int j=0;j<4;j++){
            if(j != 3){
                int k = ((j<<1)+1)&3;
                dp[i+1][k] += dp[i][j];
                dp[i+1][k] %= MOD;
            }
            if(j != 0){
                int k = ((j<<1)&3);
                dp[i+1][k] += dp[i][j];
                dp[i+1][k] %= MOD;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<4;i++){
        ans += dp[m][i];
        ans += dp[n][i];
    }
    ans -= 2;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}