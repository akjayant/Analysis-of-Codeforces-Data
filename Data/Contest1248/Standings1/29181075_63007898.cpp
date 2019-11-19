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

const int sz_n=1000015;
const int sz_m=5000015;
stack <int> s;
struct edge{
	int f,t,nxt;
} l[sz_m];
int head[sz_n],tot=0;
void build(int f,int t){
	l[tot].f=f,l[tot].t=t,l[tot].nxt=head[f];
	head[f]=tot++;
}
int n,m;
int dfs_clock,low[sz_n],dfn[sz_n];
int scc[sz_n],scc_num;
int tarjan(int u){
	low[u]=dfn[u]=++dfs_clock;
	s.push(u);

	foredge(u,i){
		int v=l[i].t;
		if(!dfn[v]){
			low[v]=tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(!scc[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		scc_num++;
		while(true){
			int f=s.top();s.pop();
			scc[f]=scc_num;
			if(f==u) break;
		}
	}
	return low[u];
}

void init(int n){
	rep(i,0,n+5) head[i]=-1,low[i]=dfn[i]=scc[i]=0;
	// mem(head,-1);
	// // mem(l,0);
	// mem(low,0);
	// mem(dfn,0);
	// mem(scc,0);
	while(!s.empty()) s.pop();
	tot=dfs_clock=scc_num=0;
}
int c[sz_n];
int in1[sz_m],in2[sz_m];//离线的数据

int getd0(){
	int cnt=0;
	rep(i,1,scc_num+1){
		if(c[i]==0) return i;
	}
	return -1;
}
vec jv,cv;
void solve(){
	//建原图
	int a,b;
	rep(i,0,m){
		scanf("%d%d",&a,&b);
		in1[i]=a,in2[i]=b;
		if(a==b) continue;
		build(a,b);
	}
	//求scc
	rep(i,1,n+1){
		if(!scc[i]) tarjan(i);
	}
	//缩点建图
	rep(i,0,n+5) head[i]=-1;
	// mem(head,-1);
	// mem(l,0);
	tot=0;
	// LOG("scc_num",scc_num);
	rep(i,0,m){
		int a=in1[i],b=in2[i];
		a=scc[a],b=scc[b];
		if(a==b) continue;
		build(a,b);
		// LOG("insert",a,b);
	}
	//求入度
	rep(i,0,n+5) c[i]=0; 
	// mem(c,0);
	rep(u,1,scc_num+1){
		foredge(u,i){
			c[l[i].f]++;
		}
	}
	//统计入度为0的点
	int jscc=getd0();
	jv.clear();cv.clear();
	rep(i,1,n+1){
		if(scc[i]==jscc) jv.push_back(i);
		else cv.push_back(i);
	}
	if(SZ(jv)>0&&SZ(jv)<n){
		puts("YES");
		printf("%d %d\n",SZ(jv),SZ(cv));
		rep(i,0,SZ(jv)){
			if(i) putchar(' ');
			printf("%d",jv[i]);
		}
			puts("");
		rep(i,0,SZ(cv)){
			if(i) putchar(' ');
			printf("%d",cv[i]);
		}
			puts("");
	}else{
		puts("NO");
	}
	// LOG("j",jv);
	// LOG("c",cv);
	// LOG("cnt",cnt);
	// return cnt;
}
int main(){
	int _=readll();
	while(_--){
		scanf("%d%d",&n,&m);
		init(n);
		solve();
		// printf("%d\n",solve());
	}
	return 0;
}