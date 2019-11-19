//by Judge
#include<cstdio>
#include<cstring>
#include<iostream>
#define Rg register
#define fp(i,a,b) for(Rg int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(Rg int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(Rg int i=head[u],v=e[i].to;i;v=e[i=e[i].nxt].to)
#define open(S) freopen(S".in","r",stdin),freopen(S".out","w",stdout)
#define ll long long
using namespace std;
const int inf=1e9+7;
const int M=1e5+3;
typedef int arr[M];
#ifndef Judge
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
char buf[1<<21],*p1=buf,*p2=buf;
inline bool cmax(int& a,int b){return a<b?a=b,1:0;}
inline bool cmin(int& a,int b){return a>b?a=b,1:0;}
inline int read(){ int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x*f;
} int a,b,c,d,k,ans1,ans2;
int main(){
	int T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read(),k=read();
		ans1=a/c+(a%c?1:0),ans2=b/d+(b%d?1:0);
		if(ans1+ans2<=k) printf("%d %d\n",ans1,ans2);
		else printf("-1\n");
	} return 0;
}