//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=100005;

int n,c[4][N],d[N],dep[N];

int lnk[N],pp;
struct ed{int nxt,to;}G[N<<1];
void ae(int u,int v){G[++pp]=(ed){lnk[u],v},lnk[u]=pp;}

void dfs(int u,int fa){
	for(int i=lnk[u];i;i=G[i].nxt)if(G[i].to!=fa)dep[G[i].to]=dep[u]%3+1,dfs(G[i].to,u);
}

signed main(){
	rd(n);
	rep(j,1,3)rep(i,1,n){
		rd(c[j][i]);
	}
	rep(i,2,n){
		int u,v;rd(u),rd(v);
		ae(u,v),ae(v,u);
		++d[u],++d[v];
	}
	rep(i,1,n)if(d[i]>2){puts("-1");return 0;}
	int rt=1;
	rep(i,1,n){
		if(d[i]&1)rt=i;
	}
	dep[rt]=1;
	dfs(rt,0);
	int w[4]={0,1,2,3};
	int mx[4]={0,1,2,3};
	int mxx=0x3f3f3f3f3f3f3f3f;
	do{
		int res=0;
		rep(i,1,n)res+=c[w[dep[i]]][i];
		if(res<mxx)mxx=res,memcpy(mx,w,sizeof(mx));
	}while(std::next_permutation(w+1,w+1+3));
	pt(mxx,'\n');
	rep(i,1,n)pt(mx[dep[i]],' ');
	return 0;
}