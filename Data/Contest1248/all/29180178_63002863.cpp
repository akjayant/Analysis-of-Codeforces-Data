#include<bits/stdc++.h>
using namespace std;

typedef long double                 ld;
typedef long long                   ll;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<string , string>       pss;

const ll MXN = 1e5 + 10;
const ll MXM = 5e2 + 10;
const ll MX5 = 4e5 + 10;
const ll MX6 = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353;

ll n, m, dp[MXN],pd[MXN];



int main(){
    //fast_io
    //file_io
    for (int i=0;i<100;i++)
    ;
    cin >> n >> m;
    if(m < n)
        swap(n, m);
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 3; i < MXN; i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]=dp[i]%MOD;
    }
    cout << (dp[n] + dp[m] - 2) % MOD;
    return 0;
}
//! N.N

