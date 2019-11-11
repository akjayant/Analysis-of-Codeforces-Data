//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,a,b,c,cnt[233],vis[233];
char ans[233];
int main() {
	int T;cin>>T;while(T--){
		string s;cin>>n>>a>>b>>c>>s;memset(cnt,0,sizeof(cnt));memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)cnt[s[i]]++;
		if(min(a,cnt['S'])+min(b,cnt['R'])+min(c,cnt['P'])>=(n+1)/2){
			puts("Yes");
			int ca=0,cb=0,cc=0;
			for(int i=0;i<n;++i){
				if(s[i]=='S'&&ca<a)ans[i]='R',++ca,vis[i]=1;
			}
			for(int i=0;i<n;++i){
				if(s[i]=='R'&&cb<b)ans[i]='P',++cb,vis[i]=1;
			}
			for(int i=0;i<n;++i){
				if(s[i]=='P'&&cc<c)ans[i]='S',++cc,vis[i]=1;
			}
			for(int i=0;i<n;++i){
				if(vis[i])continue;
				if(ca<a)ans[i]='R',++ca;
				else if(cb<b)ans[i]='P',++cb;
				else if(cc<c)ans[i]='S',++cc;
				else assert(0);
			}
			for(int i=0;i<n;++i)putchar(ans[i]);
			puts("");
		}else puts("No");
	}
	return 0;
}