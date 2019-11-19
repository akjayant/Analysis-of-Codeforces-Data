#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 1e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n, m;

ll dp[MAXN][2];


ll dP(ll a, bool b){
    if(a > n) return 0;
    if(a == n) return 1;
    if(dp[a][b]) return dp[a][b];
    return dp[a][b] = (dP(a + 1, !b) + dP(a + 2, !b))%mod;
}
ll dp2[MAXN][2];
ll d2(ll a, bool b){
    if(a > m) return 0;
    if(a == m) return 1;
    if(dp2[a][b]) return dp2[a][b];
    return dp2[a][b] = (d2(a + 1, !b) + d2(a + 2, !b))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>n>>m;
    ll dis = 2LL*d2(0, 0) - 2 + mod;
    dis %= mod;
    cout<<(dis + 2LL*dP(0, 0))%mod;
    

    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}