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
ll n,a,b,c,numR,numP,numS,ans,len,vis[maxn],T;
char s[maxn],p[maxn];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		scanf("%lld%lld%lld",&a,&b,&c);
		scanf("%s",&s);
		numR=numP=numS=0;
		mst(vis,0);
		len=strlen(s);
		rep(i,0,len-1){
			if(s[i]=='R'){
				numR++;
			}
			if(s[i]=='P'){
				numP++;
			}
			if(s[i]=='S'){
				numS++;
			}
		}
		ans=min(numR,b)+min(numP,c)+min(numS,a);
		if(ans>=(n+1)/2){
			printf("YES\n");
			rep(i,0,len-1){
				if(s[i]=='R'&&b>0){
					b--;p[i]='P';vis[i]=1;
				}
				if(s[i]=='P'&&c>0){
					c--;p[i]='S';vis[i]=1;
				}
				if(s[i]=='S'&&a>0){
					a--;p[i]='R';vis[i]=1;
				}
			}
			rep(i,0,len-1){
				if(!vis[i]){
					if(a) p[i]='R',a--;
					else if(b) p[i]='P',b--;
					else if(c) p[i]='S',c--;
				}
			}
			rep(i,0,len-1) printf("%c",p[i]);
			cout<<endl;
		} 
		else printf("NO\n");
	}
	return 0;
}
