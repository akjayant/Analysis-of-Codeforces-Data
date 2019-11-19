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
int n,a[N],b[N],sig,pre[N],suf[N];
ll Pre[N],Suf[N],pvl[N],svl[N];
ll K;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	K=readl();
	for(ri i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	sig=0;
	for(ri i=1;i<=n;++i){
		if(a[i]!=a[i-1])a[++sig]=a[i],b[sig]=1;
		else ++b[sig];
	}
	for(ri i=1;i<=sig;++i)pre[i]=pre[i-1]+b[i],Pre[i]=Pre[i-1]+(ll)b[i]*a[i],pvl[i]=(ll)pre[i]*a[i]-Pre[i];
	for(ri i=sig;i;--i)suf[i]=suf[i+1]+b[i],Suf[i]=Suf[i+1]+(ll)b[i]*a[i],svl[i]=(ll)Suf[i]-(ll)suf[i]*a[i];
	ll res=a[sig]-a[1];
	for(ri ps1=1,ps2=1;ps1<=sig;++ps1){
		while(ps2<=sig&&pvl[ps1]+svl[ps2]>K)++ps2;
		if(ps2>sig)break;
		if(ps1>=ps2)return puts("0"),0;
		res=min(res,a[ps2]-a[ps1]-(K-pvl[ps1]-svl[ps2])/suf[ps2]);
	}
	for(ri ps1=sig,ps2=sig;ps2;--ps2){
		while(ps1&&pvl[ps1]+svl[ps2]>K)--ps1;
		if(!ps1)break;
		if(ps1>=ps2)return puts("0"),0;
		res=min(res,a[ps2]-a[ps1]-(K-pvl[ps1]-svl[ps2])/pre[ps1]);
	} 
	cout<<res;
	return 0;
}