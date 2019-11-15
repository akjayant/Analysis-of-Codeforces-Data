/*****************************************************

@author: vichitr
Compiled On: 17th Oct 2019

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
#define F first
#define S second

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
	vector<int> v[n+1];
	bool f = 1;
	int k = 1;
	for(int i=1;i<=n;i++)
	{
		if(f)
		{
			for(int j=1;j<=n;j++){
				v[j].pb(k);
				k++;
			}
		}
		else{
			for(int j=n;j>0;j--){
				v[j].pb(k);
				k++;
			}
		}
		f = 1-f;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j: v[i])
			cout<<j<<" ";
		cout<<endl;
	}
}	

signed main()
{
    fast;
    int t=1;
    // cin >>t;
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