//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=2005;
int n;
ll x[MAXN],y[MAXN],c[MAXN],k[MAXN],dis[MAXN],ans,f[MAXN];
bool vis[MAXN];
vector<int>co;
ll mh(int i,int j){return abs(x[i]-x[j])+abs(y[i]-y[j]);}
int main() {
	n=read();
	for(int i=1;i<=n;++i)x[i]=read(),y[i]=read();
	for(int i=1;i<=n;++i)c[i]=dis[i]=read();
	for(int i=1;i<=n;++i)k[i]=read();
	while(1){
		int mn=-1;
		for(int i=1;i<=n;++i)if(!vis[i] && (mn==-1||dis[i]<dis[mn]))mn=i;
		if(mn==-1)break;
		ans+=dis[mn];vis[mn]=1;if(dis[mn]==c[mn])co.pb(mn);
		for(int i=1;i<=n;++i)if(!vis[i]&&dis[i]>(k[mn]+k[i])*mh(i,mn)){
			dis[i]=(k[mn]+k[i])*mh(i,mn);
			f[i]=mn;
		}
	}
	cout<<ans<<endl;
	cout<<co.size()<<endl;
	for(int i=0;i<(int)co.size();++i)cout<<co[i]<<" ";cout<<endl;
	cout<<n-co.size()<<endl;
	for(int i=1;i<=n;++i)if(f[i])cout<<f[i]<<" "<<i<<endl;
	return 0;
}