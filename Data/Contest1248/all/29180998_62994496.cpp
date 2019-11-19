#include<bits/stdc++.h>
using namespace std;
#define maxn 100050
#define INF 0x3f3f3f
#define ll long long
#define cin(x) scanf("%d",&x)
#define cout(x) printf("%d\n",x)
#define rep(i,k,n) for(ll i=k;i<=n;i++)
#define mst(a,k) memset(a,k,sizeof(a));
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
inline void write(int x){
	char c[20];int l=0;
	while(x) c[++l]=x%10+48,x/=10;
	while(l) putchar(c[l--]);
	putchar('\n');
}
const int MOD = 1e9 + 7;
ll f[maxn],n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	f[0]=1,f[1]=1;
	rep(i,2,max(n,m)){
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	//printf("%lld %lld %lld\n",f[n],m,f[m]);
	printf("%lld",((f[n]-1)*2+2*f[m])%MOD);
	return 0;
}