#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18,mod=1e9+7;
string s;
ll dp[N];
ll solve(ll i)
{
	ll n=s.size();
	if(i==n)
	{
		return 1;
	}
	if(dp[i]==-1)
	{
		dp[i]=0;
		if(i==n-1)
		{
			dp[i]=solve(i+1);
		}
		else
		{
			if(s[i]==s[i+1]&&(s[i]=='n'||s[i]=='u'))
			{
				dp[i]=(solve(i+1)+solve(i+2))%mod;
			}
			else
			{
				dp[i]=solve(i+1);
			}
		}
	}
	return dp[i];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> s;
	memset(dp,-1,sizeof(dp));
	lp(i,0,s.size())
	{
		if(s[i]=='m'||s[i]=='w')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<solve(0)<<endl;
	return 0;
}