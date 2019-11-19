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
template<typename T>inline T abs(const T&x){if(x<0)return-x;return x;}

const int N=2005;

int n,a[N],q[N],g[N][N],dis[N],X[N],Y[N],pre[N];bool used[N];

signed main(){
	memset(dis,63,sizeof(dis));
	memset(g,63,sizeof(g));
	rd(n);
	rep(i,1,n){
		rd(X[i]),rd(Y[i]);
	}
	rep(i,1,n){
		int x;rd(x);
		g[0][i]=g[i][0]=x;
	}
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rep(j,i+1,n)
		g[i][j]=g[j][i]=(abs(X[i]-X[j])+abs(Y[i]-Y[j]))*(a[i]+a[j]);
	dis[0]=0;
	int ans=0;
	for(int _=0;_<=n;++_){
		int id=-1;
		rep(i,0,n)if(!used[i]&&(id==-1||dis[i]<dis[id]))id=i;
//		debug(">>> %lld %lld\n",id,dis[id]);
		used[id]=1,ans+=dis[id];
		rep(i,0,n)if(!used[i]&&g[id][i]<dis[i])dis[i]=g[id][i],pre[i]=id;
	}
	pt(ans,'\n');
	rep(i,1,n)if(pre[i]==0)q[++*q]=i;
	pt(*q,'\n');
	rep(i,1,*q)pt(q[i],i==*q?'\n':' ');
	int tot=0;
	rep(i,1,n){
		if(pre[i])++tot;
	}
	pt(tot,'\n');
	rep(i,1,n){
		if(pre[i]){
			pt(pre[i],' ');
			pt(i,'\n');
		}
	}
	return 0;
}