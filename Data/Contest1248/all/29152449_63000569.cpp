#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128 LL;
//typedef unsigned long long ull;
//#define F first
//#define S second
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
const ld PI=acos(-1);
const ld eps=1e-9;
//unordered_map<int,int>mp;
#define ls (o<<1)
#define rs (o<<1|1)
#define pb push_back
const int seed=131;
const int M = 1e5+7;
const ll mod=1e9+7;
ll dp[M][4];//第几排I,这两排类型J   方案数 
/*
0   OO
1	XX
2	OX
3	XO
*/
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int n,m;
  	cin>>n>>m;
  	dp[1][2]=1,dp[1][3]=1;
  	for(int i=2;i<=max(n,m);i++)
  	{
  		dp[i][0]=dp[i-1][3];
  		dp[i][1]=dp[i-1][2];
  		dp[i][2]=(dp[i-1][0]+dp[i-1][3])%mod;
  		dp[i][3]=(dp[i-1][1]+dp[i-1][2])%mod;
	}
	ll h=dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3];
	ll l=dp[m][0]+dp[m][1]+dp[m][2]+dp[m][3];
	//cout<<h<<" "<<l<<endl;
	cout<<(h+l-2+mod)%mod<<endl;
	return 0;
}