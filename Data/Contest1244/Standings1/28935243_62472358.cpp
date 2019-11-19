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
const int N=1005;
ll n,p,d,w;
inline void exgcd(ll a,ll b,ll&x,ll&y){
	if(!b){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll t=x;
	x=y,y=t-a/b*y;
}
inline long long mmul ( long long a, long long b, const long long& Mod )  {
    a %= Mod, b %= Mod ;
    return ( a * b - ( long long ) ( ( ( long double ) a * b + 0.5 ) / Mod ) * Mod ) % Mod ;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=1;tt;--tt){
		n=readl(),p=readl(),w=readl(),d=readl();
		ll g=__gcd(d,w);
		if(p%g){
			puts("-1");
			continue;
		}
		p/=g,d/=g,w/=g;
		ll x,y;
		exgcd(w,d,x,y);
		y=(y%w+w)%w;
		y=y*(p%w)%w;
		x=(p-d*y)/w;
		if(x<0){
			puts("-1");
			continue;
		}
		if(n-x-y<0){
			puts("-1");
			continue;
		}
		cout<<x<<' '<<y<<' '<<n-x-y<<'\n';
	}
	return 0;
}