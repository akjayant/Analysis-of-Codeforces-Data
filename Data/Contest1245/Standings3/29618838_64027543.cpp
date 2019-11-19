#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl "\n"
#define ui unsigned int
#define lu unsigned long long
#define mod 1000000007
#define ld long double
#define f(i, n) for(ll i = 0; i < n; i++)
#define ff(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define v vector<ll>
#define vv vector<vector<ll> >
#define vs vector<string>
#define vpr vector<pair<ll,ll>>
#define fi first
#define se second
#define all(x)  x.begin(),x.end()
#define bg(x)  x.begin()
#define sz(x)  x.size()
#define in(x,n) f(i,n) cin>>x[i]
#define out(x,n) f(i,n) cout<<x[i]<<" "
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define mxt(a) *(max_element(a.begin(),a.end()))
#define mnt(a)  *(min_element(a.begin(),a.end()))
#define mem(x,val) memset(x,val,sizeof(x))
#define tc    ll t;cin>>t;while(t--)
#define prfloat(val,precise) cout<<fixed<<setprecision(precise)<<val<<endl;
const ld PI = 2 * acos(0.0);
void yes(){ cout<<"YES\n";}
void no(){cout<<"NO\n";cout<<-1<<"\n";exit(0);}
ll m(ll a){ return (a+mod)%mod;}
ll cel(ll x1,ll y1){ ;if((x1%y1)==0)return x1/y1;return x1/y1+1;}
ll power(ll a,ll b){ if(b==0)return 1;ll d=power(a,b/2);d=m(d*d);
if(b&1)d=m(d*a);return d;}
int pa[100005];
int size1[100005];
void init1(int n,v &c)
{
    for(int i=0;i<n;i++)
    {
    	pa[i]=i;
    	size1[i]=c[i];
    }
}
int root(int u)
{
	while(pa[u]!=u)
	{
		pa[u]=pa[pa[u]];
		u=pa[u];
	}
	return u;
}
void un(int u,int v1)
{

		int u_root=root(u);
		int v_root=root(v1);
		if(u_root==v_root)
			return    ;
	if(size1[u_root] > size1[v_root])
	{
		pa[u_root]=v_root;
		size1[u_root]=size1[v_root];
	}
	else
	{
		pa[v_root]=u_root;
		size1[v_root]=size1[u_root];

	}
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  v x(n),y(n);
  f(i,n)
  cin>>x[i]>>y[i];
  v c(n),k(n);
  in(c,n);in(k,n);
  init1(n,c);
  vector<pair<int,pair<int,int>>>edge;
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++)
  	{
  		if(i!=j)
  		{
  			int cost=0;
  			int d=abs(x[i]-x[j])+abs(y[i]-y[j]);
  			cost=d*(k[i]+k[j]);
  			edge.pb({cost,{i,j}});
  		}
  	}
  }
  sort(all(edge));
  int l=sz(edge);
  int tcost=0;
  f(i,n)
  tcost+=c[i];
  vpr ans;
  for(int i=0;i<l;i++)
  {
  	int u1=root(edge[i].se.fi);
  	int u2=root(edge[i].se.se);
  	if(u1==u2)
  		continue;
  	int mx=max(size1[u1],size1[u2]);
  	if(mx >= edge[i].fi)
  	{
  		un(edge[i].se.fi,edge[i].se.se);
  		ans.pb({edge[i].se.fi,edge[i].se.se});
  		tcost-=mx;
  		tcost+=edge[i].fi;
  	}
  }
  v ansv;
  for(int i=0;i<n;i++)
  {
  	if(root(i)==i)
  	{
  		ansv.pb(i+1);
  	}
  }
  cout<<tcost<<endl;
  cout<<sz(ansv)<<endl;
  for(auto it:ansv)
  	cout<<it<<" ";
  cout<<endl;
  cout<<sz(ans)<<endl;
  for(auto it:ans)
  	cout<<it.first+1<<" "<<it.second+1<<endl;

}