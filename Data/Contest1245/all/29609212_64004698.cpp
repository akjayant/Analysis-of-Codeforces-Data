#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll          long long
#define pb          push_back
#define eb 			emplace_back
#define mp 			make_pair
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define fi          first
#define si          second
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define checkbit(n, b) ((n >> b) & 1)
#define mod        1000000007
#define puts(n)		cout<<n;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define setbits(x) __builtin_popcount(x)
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
ll posx[]={1,-1,0,0};
ll posy[]={0,0,1,-1};

void solve()
{
    string s;
    ll i,l;
    cin>>s;
    l=s.length();
    for(i=0;i<l;i++)
    {
        if(s[i]=='m' or s[i]=='w')
        {
            cout<<0;
            return;
        }
    }
    ll dp[l+1];
    dp[0]=1;
    for(i=1;i<=l;i++)
    {
        if(s[i-1]!='n' and s[i-1]!='u')
        {
            dp[i]=dp[i-1];
            continue;
        }
        if(i==1)
        {
            dp[i]=dp[i-1];
            continue;
        }
        if(s[i-2]=='n' and s[i-1]=='n')
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        else if(s[i-2]=='u' and s[i-1]=='u')
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        else
        dp[i]=dp[i-1];
    }
    cout<<dp[l];
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
