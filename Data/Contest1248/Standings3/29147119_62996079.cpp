#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) 
{
	if (b < 0) return 0;
	ll ret = 1;
	a %= mod;
	while (b) {
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret % mod;
}
ll dp[100005][4];
 ll n,m;
 void read()
 {
    cin>>n>>m;
 }
 ll readd()
 {
    if(n<m)
    {
        int t = n ;
        n = m ;
        m = t ;
    }
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-1][3])%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
        dp[i][2]=dp[i-1][0];
        dp[i][3]=dp[i-1][1];
    }
    return ((dp[n][1]+dp[n][2])%mod+(dp[n][3]+dp[n][0])%mod+(dp[m][1]+dp[m][0]+dp[m][2]+dp[m][3]-2)%mod)%mod;

 }
int main()
{
    read();
    cout << readd() <<endl;
}
