#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))s[++top]=ch,ch=gc();
	return top;
}
namespace modular{
	const int mod=998244353;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
const int N=100005;
int n,vl[N][4],q[N],hd,tl,vs[N],col[N];
ll f[N][4][4];
pii pre[N][4][4];
vector<int>e[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=3;++i)for(ri j=1;j<=n;++j)vl[j][i]=read();
	for(ri i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	for(ri i=1;i<=n;++i)if(e[i].size()>2)return puts("-1"),0;
	for(ri i=1;i<=n;++i){
		if(e[i].size()==1){
			q[hd=tl=1]=i;
			break;
		}
	}
	while(hd<=tl){
		int x=q[hd++];
		vs[x]=1;
		for(ri i=0,v;i<e[x].size();++i){
			if(vs[v=e[x][i]])continue;
			q[++tl]=v;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(ri i=1;i<=3;++i)for(ri j=1;j<=3;++j)if(i!=j)f[1][i][j]=vl[q[1]][j];
	for(ri i=2;i<=n;++i){
		for(ri j=1;j<=3;++j){
			for(ri k=1;k<=3;++k){
				for(ri l=1;l<=3;++l){
					if(j!=k&&k!=l&&j!=l){
					if(f[i-1][l][j]+vl[q[i]][k]<f[i][j][k]){
						f[i][j][k]=f[i-1][l][j]+vl[q[i]][k];
						pre[i][j][k]=pii(l,j);
					}
					}
				}
			}
		}
	}
	ll res=1e18;
	pii las;
	for(ri i=1;i<=3;++i)for(ri j=1;j<=3;++j){
		if(i!=j)if(f[n][i][j]<res){
			res=f[n][i][j];
			las=pii(i,j);
		}
	}
	int ps=n;
	while(ps){
		col[q[ps]]=las.se;
		las=pre[ps][las.fi][las.se];
		--ps;
	}
	cout<<res<<'\n';
	for(ri i=1;i<=n;++i)cout<<col[i]<<' ';
	return 0;
}