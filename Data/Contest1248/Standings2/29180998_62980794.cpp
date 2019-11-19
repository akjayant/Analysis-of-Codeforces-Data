#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
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
ll T,n,m,x,y,red1,black1,red2,black2;
int main(){
	cin>>T;
	while(T--){
		red1=0,black1=0;
		red2=0,black2=0;
		scanf("%lld",&n);
		rep(i,1,n){
			scanf("%lld",&x);
			if(x%2==0) red1++;
			else black1++;
		}
		scanf("%lld",&m);
		rep(i,1,m){
			scanf("%lld",&y);
			if(y%2==0) red2++;
			else black2++;
		}
		printf("%lld\n",red1*red2+black1*black2);
	}
	
	return 0;
}



