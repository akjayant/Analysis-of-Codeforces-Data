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
	int t;
	ll n,m,k;
	cin>>t;
	while (t--){
		cin>>n;
		ll a1=0;
		ll a2=0;
		for (int i=1;i<=n;i++){
			cin>>k;
			if (k%2==0) a1++;
		}
		cin>>m;
		for (int i=1;i<=m;i++){
			cin>>k;
			if (k%2==0) a2++;
		}
		ll sum=a1*a2+(n-a1)*(m-a2);
		cout<<sum<<endl;
	}
	return 0;
}