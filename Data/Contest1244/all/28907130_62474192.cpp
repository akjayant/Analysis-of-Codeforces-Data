/*****************************************************

@author: vichitr
Compiled On: 13th Oct 2019

*****************************************************/
#include<bits/stdc++.h>
#define MAX 9223372036854775807
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define ip pair<int, int>

#define loop(i,n) for(int i=0;i<n;i++)
#define loops(i,s,n) for(int i=s;i<=n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const ll MOD = 1e9+7;
const ll SZ = 107;
const ll N = 3e5+1;
const ll M = 2e5+7;

ll pwr(ll x, ll y)
{
    ll r = 1LL;
    while(y)
    {
        if(y&1)
            r = (r * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

int inv(int x)
{
	return pwr(x, MOD-2ll);
}


void solve()
{
	int n; cin>>n;
	string s; cin>>s;
	int ans = 0;
	vector<int> pre(n+5, 0), post(n+5, 0);
	pre[0] = 1;
	if(s[0]=='1')
		pre[0]++;
	for(int i=1;i<n;i++)
	{
		pre[i] = pre[i-1]+1;
		if(s[i]=='1')
			pre[i]++;

	}
	post[n-1] = 1;
	if(s[n-1]=='1')
		post[n-1]++;
	for(int i=n-2;i>=0;i--)
	{
		post[i] = post[i+1]+1;
		if(s[i]=='1')
			post[i]++;
	}
	vector<int> ones;
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			ones.pb(i);

	ans = max(pre[n-1], post[0]);
	for(int i=1;i<ones.size();i++)
	{
		int here = 2*(ones[i]-ones[i-1]);
		ans = max(ans, here+pre[ones[i-1]]);
		ans = max(ans, here + post[ones[i]]);
	}

	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			ans = max(ans, 2*i+2);
			ans = max(ans, 2*(n-i));
		}
	}
	cout<<ans<<endl;

}

signed main()
{
    fast;
    int t=1;
    cin >>t;
    while(t--){
        solve();
        
    }
    return 0;
}

/*****************************

5 4
1 2
4 3
1 4
3 4

1

6 5
2 3
2 1
3 4
6 5
4 5

0

****************************/