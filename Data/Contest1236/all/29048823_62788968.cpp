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

#define loop(i,n) for(int i=0;i<n;i++)
#define loops(i,s,n) for(int i=s;i<=n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const ll MOD = 1e9+7;
const ll SZ = 107;
const ll N = 3e5+1;
const ll M = 2e5+7;

ll pwr(ll x, ll y, ll MO)
{
    ll r = 1LL;
    while(y)
    {
        if(y&1)
            r = (r * x) % MO;
        y >>= 1;
        x = (x * x) % MO;
    }
    return r;
}

int inv(int x)
{
	return pwr(x, MOD-2ll, MOD);
}


void solve()
{
	int n, m; cin>>n>>m;
	int k = pwr(2, m, MOD)-1;
	int ans = pwr(k, n, MOD);
	cout<<ans;
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