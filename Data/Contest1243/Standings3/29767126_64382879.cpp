// Etavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
#define re register
#define ll long long
#define il inline
#define rep(i,s,t) for(re int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(re int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define pt(ch) putchar(ch)
#define pti(x) printf("%d",x)
#define ptll(x) printf("%I64d",x)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
// c_ints
il int ci(){
	re char ch;int f=1;
	while(!isdigit(ch=getchar()))f= ch=='-'?-1:1 ;
	re int x= ch^'0';
	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');
	return f*x;
}
enum{N=10024};
char s[N],t[N];
int pos[N];
int main(){
	int T=ci();
	while( T-- ){
		int n=ci();
		scanf("%s%s",s+1,t+1);
		int cnt= 0;
		rep(i,1,n) if( s[i]!=t[i] ){
			pos[++cnt]= i;
			if( cnt==3 ) break;
		}
		if( cnt==3 ) puts("NO");
		else if( cnt==1 ) puts("NO");
		else if( cnt==0 ) puts("YES");
		else if( cnt==2 ){
			if( s[pos[1]]==s[pos[2]]
			 && t[pos[1]]==t[pos[2]] ) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
