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
ll T,n,a[maxn];
vector<ll> v;
char s[maxn],t[maxn];
int main(){
	scanf("%lld",&T);
	while(T--){
		while(!v.empty()) v.clear();
		scanf("%lld",&n);
		scanf("%s%s",&s,&t);
		rep(i,0,n-1){
			if(s[i]!=t[i]) v.push_back(i);
		}
		if(v.size()!=2) printf("No\n");
		else{
			if(s[v[0]]==s[v[1]]&&t[v[0]]==t[v[1]]) printf("Yes\n");
			else  printf("No\n");
		}
	}
	return 0;
}
