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
    ll n,i,a1,b,c;
    cin>>n>>a1>>b>>c;
    string s;
    cin>>s;
    int ans=0;
    char a[n];
    for(i=0;i<n;i++)
    {
        a[i]='A';
        if(s[i]=='R')
        {
            if(b>0)
            {
                b--;
                ans++;
                a[i]='P';
            }
        }
        else if(s[i]=='P')
        {
            if(c>0)
            {
                c--;
                ans++;
                a[i]='S';
            }
        }
        else
        {
            if(a1>0)
            {
                a1--;
                ans++;
                a[i]='R';
            }
        }
    }
    ll r=n/2+n%2;
    if(ans<r)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(i=0;i<n;i++)
    {
        if(a[i]!='A')
        cout<<a[i];
        else
        {
            if(a1>0)
            {
                cout<<"R";
                a1--;
            }
            else if(b>0)
            {
                cout<<'P';
                b--;
            }
            else
            {
                cout<<"S";
                c--;
            }
        }
    }
    cout<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
