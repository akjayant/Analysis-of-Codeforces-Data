#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=2e3+50;
const int mod=1e9+7;
using namespace std;
int n,i,j,u,v,p[nmax],sz[nmax],id[nmax];
ll l[nmax],r[nmax],a[nmax],b[nmax],vl[nmax],sm[nmax],rs,x;
vector<pair<ll,pair<int,int> > >vc;
vector<pair<int,int> >vec[nmax],vcb;
vector<int>vca;
int fnd(int x)
{
	if(p[x]==x)return x;
	return p[x]=fnd(p[x]);
}
void uni(int x,int y,ll z)
{
	int xx=x,yy=y;
	x=fnd(x),y=fnd(y);
	if(x==y)return;
	if(sz[x]<sz[y])swap(x,y);
	if(min(vl[x],vl[y])+z+sm[x]+sm[y]<=vl[x]+vl[y]+sm[x]+sm[y])
	{
		p[y]=x;
		sz[x]+=sz[y];
		vl[x]=min(vl[x],vl[y]);
		if(vl[x]==vl[y])id[x]=id[y];
		sm[x]+=sm[y]+z;
		sm[y]=0;
		for(int i=0;i<vec[y].size();i++)vec[x].pb(vec[y][i]);
		vec[x].pb(mkp(xx,yy));
		vec[y].clear();
	}
}
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			x=abs(l[i]-l[j])+abs(r[i]-r[j]);
			x*=(b[i]+b[j]);
			vc.pb(mkp(x,mkp(i,j)));
		}
	}
	sort(vc.begin(),vc.end());
	for(i=1;i<=n;i++)
	{
		vl[i]=a[i];
		id[i]=i;
		p[i]=i;
		sz[i]=1;
		sm[i]=0;
	}
	for(i=0;i<vc.size();i++)
	{
		v=vc[i].sc.fr,u=vc[i].sc.sc;
		x=vc[i].fr;
		uni(v,u,x);
	}
	for(i=1;i<=n;i++)
	{
		if(fnd(i)!=i)continue;
		rs+=sm[i]+vl[i];
		vca.pb(id[i]);
		for(j=0;j<vec[i].size();j++)vcb.pb(vec[i][j]);
	}
	cout<<rs<<endl<<(int)vca.size()<<endl;
	for(i=0;i<(int)vca.size();i++)cout<<vca[i]<<" ";
	cout<<endl<<(int)vcb.size()<<endl;
	for(i=0;i<(int)vcb.size();i++)cout<<vcb[i].fr<<" "<<vcb[i].sc<<endl;
	return 0;
}
