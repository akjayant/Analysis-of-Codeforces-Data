#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dir[8][2]={{1,0},{0,1},{1,1},{1,-1},{-1,1},{-1,-1},{0,-1},{-1,0}};
#define pi acos(-1)
#define ls rt<<1
#define rs rt<<1|1
#define me0(s) memset(s,0,sizeof(s))
#define me1(s) memset(s,1,sizeof(s))
#define mef(s) memset(s,-1,sizeof(s))
#define meinf(s) memset(s,inf,sizeof(s))
#define llinf 1e18
#define inf 1e9
const int N=1e6+6;
int a[N];
inline int read() {
    char c=getchar(); int x=0, f=1;
    while(c<'0'|c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
ll exgcd(ll a,ll b){
	if(b==0) return a;
	exgcd(b,a%b);
}
ll q_pow(ll a,ll b,ll mod){
	ll anss=1;
	while(b){
		if(b&1) anss=anss*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return anss;
}
ll q_mul(ll a,ll b,ll mod){
	ll anss=0;
	while(b){
		if(b&1) anss=(anss+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return anss;
}
int main(int argc, char * argv[]) {
    ios::sync_with_stdio(false);
	ll n;
	ll sum=0;
	ll c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>n/2;i--){
		c+=a[i];
	}
	ll ans=c*c+(sum-c)*(sum-c);
	cout<<ans<<endl;
    return 0;
}