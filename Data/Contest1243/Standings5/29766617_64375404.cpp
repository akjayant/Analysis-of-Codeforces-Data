#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define ll long long
#define cin(x) scanf("%d",&x)
#define cout(x) printf("%d\n",x)
#define rep(i,k,n) for(ll i=k;i<=n;i++)
#define mst(a,k) memset(a,k,sizeof(a));
const ll INF = 1e12 + 5;
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
ll T,n,m,a[maxn];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,1,n){
			scanf("%lld",&a[i]);
		}
		for(ll i=1000;i>=1;i--){
			ll num=0;
			rep(j,1,n){
				if(a[j]>=i) num++;
			}
			if(num>=i){
				printf("%lld\n",i);
				break;
			}
		}
	}
	
	return 0;
}
