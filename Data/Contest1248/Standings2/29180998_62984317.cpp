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
ll cmp(ll a,ll b){
	return a<b;
}
ll n,sum,s,t,a[maxn];
int main(){
	scanf("%lld",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	rep(i,1,n/2) s+=a[i];
	printf("%lld",s*s+(sum-s)*(sum-s));
	return 0;
}