#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define MO 1000000007
#define mem(a,s) memset(a,s,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lop(i,s,e) for(int i=s;i<=e;i++)
#define lopi(i,s,e) for(int i=s;i>=e;i--)
#define prina(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl; 
#define prin2da(a,n,m) lop(i,0,n-1){lop(j,0,m-1)cout<<a[i][j]<<" ";cout<<endl;} 
using namespace std;
ll n,m;
string s,t;
int siz[100001];
int root(int a[],int i)
{
  while(a[i]!=i)
  {
    i=a[i];
  }
  return i;
}
int find(int a[],int f,int s)
{
  int r1 = root(a,f);
  int r2 = root(a,s);
  if(r1==r2) return 1;
  return 0;
}
void uni(int a[],int f,int s)
{
  int r1 = root(a,f);
  int r2 = root(a,s);
  if(r1==r2)
  return ;
  if(siz[r1]>siz[r2])
  {
    a[r2]=r1;
    siz[r1]+=siz[r2];
  }
  else
  {
    a[r1]=r2;
    siz[r2]+=siz[r1];
  }
}
bool cmp(pair<ll, pair<ll ,ll> > a,pair<ll, pair<ll ,ll> > b)
{
	if(a.ff<=b.ff)
		return 1;
	else
		return 0;
}
int main()
{
IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ll n;
cin>>n;
vector<pair<int,int > > loc ;
lop(i,0,n-1)
{
	ll x,y;
	cin>>x>>y;
	loc.pb({x,y});
}
int a[n+1];

lop(i,0,100000)
siz[i]=1;
mem(a,0);
lop(i,0,n)
a[i]=i;

ll cost[n];
ll k[n];
lop(i,0,n-1)
cin>>cost[i];

lop(i,0,n-1)
cin>>k[i];

vector<pair<ll, pair<ll ,ll> > > g;
lop(i,1,n)
{
	lop(j,i+1,n)
	{
		ll dist=abs(loc[i-1].ff-loc[j-1].ff)+abs(loc[i-1].ss-loc[j-1].ss);
		ll cc=dist*(k[i-1]+k[j-1]);
		g.pb({cc,{i,j}});
	}
}
ll ans=0;
lop(i,1,n)
{
g.pb({cost[i-1],{0,i}});
}
sort(g.begin(),g.end(),cmp);
int coi=0,vt=0;
vector<int > ass;
vector<pair<int ,int > > anss;
for(auto x: g)
{
	int u=x.ss.ff,v=x.ss.ss;
	if(find(a,u,v)==1)
		continue;
	else
	{
		if(u==0)
			{vt++;ass.pb(v);}
		else if(v==0)
			{vt++;ass.pb(u);}
		else
		{
			coi++;
			anss.pb({u,v});
		}
		ans=ans+x.ff;
		uni(a,u,v);
	}
}
cout<<ans<<endl;
cout<<vt<<endl;
for(auto x: ass)
	cout<<x<<" ";
cout<<endl;
cout<<coi<<endl;
for(auto x: anss)
	cout<<x.ff<<" "<<x.ss<<endl;
}

