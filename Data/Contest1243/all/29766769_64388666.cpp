#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t;

ll obeb(ll a,ll b)
{
   if(b==0)
        return a;
   else
        return obeb(b,a%b);
}

vector<ll> v;


int main()
{
	fast;
	cin>>n;
	if(n<3)
		return cout<<n,0;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i!=0)
			continue;
		if(i*i==n)
		{
			v.pb(i);
			break;
		}
		v.pb(i);
		v.pb(n/i);
	}
	v.pb(n);
	ll x=0;
	for(int i=0;i<v.size();i++)
		x=obeb(v[i],x);
	cout<<x<<endl;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/