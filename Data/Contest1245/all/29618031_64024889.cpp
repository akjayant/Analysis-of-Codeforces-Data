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

ll n,m,ar[N],sum,t,dad[N];

int find(ll x)
{
	if(dad[x]==x)
		return x;
	return dad[x]=find(dad[x]);
}
void unite(int x,int y)
{
	dad[find(x)]=find(y);
	return;
}

vector<pair<lli,lli> > v;
vector<ll> ans1;
vector<lli> ans2;

ll kab[N],mn=INT_MAX,mni;

lli p[N];

int main()
{
	fast;
	cout<<endl;
	cin>>n;
	fo(i,1,n)
	{
		cin>>p[i].fi>>p[i].se;
		dad[i]=i;
	}
	fs(ar,n);
	fs(kab,n);
	fo(i,1,n)
	{
		if(ar[i]<mn)
			mn=ar[i],mni=i;
	}
	sum+=mn;
	fo(i,1,n)
		fo(j,i+1,n)
		{
			ll x=0;
			x=(kab[i]+kab[j])*(fabs(p[i].fi-p[j].fi)+fabs(p[i].se-p[j].se));
			v.pb({{x,2},{i,j}});
		}
		fo(i,1,n)
		v.pb({{ar[i],1},{i,mni}});
		sort(v.begin(),v.end());
	ans1.pb(mni);
	// cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		ll x=v[i].se.fi;
		ll y=v[i].se.se;
		ll c=v[i].fi.fi;
		ll t=v[i].fi.se;
		if(find(x)==find(y))
			continue;
		if(t==1)
			ans1.pb(x);
		else
			ans2.pb({x,y});
		unite(y,x),sum+=c;
	}
	cout<<sum<<endl;
	cout<<ans1.size()<<endl;
	for(int i=0;i<ans1.size();i++)
		cout<<ans1[i]<<sp;
	cout<<endl;
	cout<<ans2.size()<<endl;
	for(int i=0;i<ans2.size();i++)
		cout<<ans2[i].fi<<sp<<ans2[i].se<<endl;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/