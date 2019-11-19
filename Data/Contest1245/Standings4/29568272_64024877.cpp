#include <stdio.h>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
// #include <unordered_map>
#define SZ(a) ((int)(a.size()))
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
#ifdef LOCAL
template<class T>void print_array(T *a,T *end){printf("#[");for(;a<end;++a)cout<<(*a)<<',';cout<<"\b]\n";};
template<class T>ostream &operator<<(ostream&os,vector<T>V){os<<"[";for(auto vv:V)os<<vv<<",";return os<<"\b]";}
void dbg(){cout<<"\b \n";}
template<typename T,typename...A>void dbg(T a,A...x){cout<<(a)<<',';dbg(x...);}
#define LOG(x...) {cout<<'#';dbg(x);}
#else
#define print_array(...)
#define LOG(...)
#endif
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double PI=acos(-1.0);
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}
//const int sz=;

const int sz=3009;
struct edge{
	int f,t;ll d;
	friend bool operator<(const edge &a,const edge &b){
		return a.d<b.d;
	}
};
vector<edge> g;
void insert(int f,int t,ll d){
	g.push_back({f,t,d});
}
ll x[sz],y[sz];
ll c[sz],k[sz];

int par[sz];
void init(int n){
	for(int i=0;i<n;i++) par[i]=i;
}
int find(int x){
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	par[x]=y;
}
bool same(int x,int y){
	return find(x)==find(y);
}
int n;
vector<pii> eds;
vec bus;
ll krus(){
	sort(g.begin(), g.end());
	int cnt=0;ll ans=0;
	rep(i,0,SZ(g)){
		if(!same(g[i].f,g[i].t)){
			if(g[i].t==n) bus.push_back(g[i].f+1);
			else eds.push_back({g[i].f+1,g[i].t+1});
			ans+=g[i].d;
			unite(g[i].f,g[i].t);
			// LOG(g[i].f,g[i].t,g[i].d);
			cnt++;
			if(cnt==n) break;
		}
	}
	return ans;
}

int main(){
	n=readll();
	rep(i,0,n){
		x[i]=readll(),y[i]=readll();
	}
	init(n+5);
	rep(i,0,n) c[i]=readll();
	rep(i,0,n) k[i]=readll();
	rep(i,0,n){
		rep(j,0,i){
			insert(i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])));
		}
		insert(i,n,c[i]);
	}
	ll ans=krus();
	cout<<ans<<endl;
	cout<<SZ(bus)<<endl;
	rep(i,0,SZ(bus)){
		if(i) cout<<' ';
		cout<<bus[i];
	}
	cout<<endl;
	cout<<SZ(eds)<<endl;
	for(pii x:eds) cout<<x.first<<' '<<x.second<<endl;
	return 0;
}