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
    ll n,i,j;
    cin>>n;
    ll a[n][n];
    ll c=1;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=c;
                c++;
            }
        }
        else
        {
            for(j=n-1;j>=0;j--)
            {
                a[i][j]=c;
                c++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
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
