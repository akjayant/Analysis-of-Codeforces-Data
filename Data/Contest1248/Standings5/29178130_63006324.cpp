#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
long countWays(int n) 
{ 
    ll dp[n + 1]; 
    memset(dp, 0, sizeof(dp));
    dp[1] = 2; 
    int same = 0, diff = 2; 
    int i=2;
    while(i <= n) { 
        same = diff; 
        diff = dp[i-1]; 
        dp[i] = (same + diff) % mod;
        i++; 
    } 
    return dp[n]; 
}  
int main(){
    ll n,m;
    cin>>n>>m;
    cout<<(countWays(n) + countWays(m) -2)%mod;

    return 0;
}