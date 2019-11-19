#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
ii pos[2005];
int c[2005],k[2005];
ll dist(int i,int j)
{
	return abs(pos[i].F-pos[j].F) + abs(pos[i].S - pos[j].S);
}
class UnionFind
{
private:
	vi p;
public:
	UnionFind(int n)
	{
		p.assign(n+5,0);
		for(int i=0;i<=n;i++)p[i]=i;
	}
	void us(int i,int j)
	{
		p[fs(i)]=fs(j);
	}
	int fs(int i)
	{
		return (p[i]==i)? i:(p[i]=fs(p[i]));
	}
};
int main()
{
    sint(n);
	for(int i=1;i<=n;i++){
		sint2(x,y);
		pos[i]=mkp(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		int1(c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int1(k[i]);
	}
	ll ans=0;
	vector<tuple<ll,int,int> > v;
	for(int i=1;i<=n;i++)v.pb(mkt(c[i],0,i));
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			v.pb(mkt((k[i]+k[j])*dist(i,j),i,j));
	sort(all(v));
	UnionFind uf(n);
	vi power;
	vii wire;
	for(int i=0;i<v.size();i++)
	{
		ll w;
		int x,y;
		tie(w,x,y) = v[i];
		// debug(w);
		// debug(x);
		// debug(y);
		// endl;
		if(uf.fs(x)!=uf.fs(y))
		{
			uf.us(x,y);
			ans+=w;
			if(x==0)
			{
				power.pb(y);
			}
			else wire.pb(mkp(x,y));
		}
	}
	Wl(ans);
	printf("%d\n",power.size());
	for(int i=0;i<power.size();i++)
	{
		W(power[i]);
	}
	endl;
	printf("%d\n",wire.size());
	for(int i=0;i<wire.size();i++)
	{
		printf("%d %d\n",wire[i].F,wire[i].S);
	}
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
