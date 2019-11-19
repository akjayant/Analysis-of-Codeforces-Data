#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
using namespace std;
#define ll long long
const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
ll quickpow(ll a, ll b) {
	if (b < 0) return 0;
	ll ret = 1;
	a %= MOD;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ret % MOD;
}
ll dp[100005][4];
int main()
{
    /*
    1 1 2
    1 2 4 01 10 00 11
    1 3 6  001 101 010 100 110 011
    1 4 10  0101 1010 1100 0011 1001 0110 1011 1101 0100 0010
    2 1 4 01 10 00 11
    2 2 6
    2 3 8
    2 4 12
    2 6 18
    2 7 28
    */
    ll n,m;
    cin>>n>>m;
    if(n<m)swap(n,m);
    dp[1][0]=dp[1][1]=1;//dp[1][3]=dp[1][2]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-1][3])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=dp[i-1][0];
        dp[i][3]=dp[i-1][1];
        //cout<<dp[i][0]<<endl;
        //cout<<i<<' '<<dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]<<endl;
    }
    cout<<((dp[n][1]+dp[n][2])%MOD+(dp[n][3]+dp[n][0])%MOD+(dp[m][1]+dp[m][0]+dp[m][2]+dp[m][3]-2)%MOD)%MOD<<endl;
    return 0;
}
