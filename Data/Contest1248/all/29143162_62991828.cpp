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
enum{N=100024};
const int mod= 1e9+7;
ll f[N];
int main(){
	int n=ci(), m=ci();
	int ed= max(n,m)+2;
	f[1]=1;
	rep(i,2,ed) f[i]= (f[i-1]+f[i-2])%mod;
//	rep(i,1,10) printf("%d ",f[i]);
	ptll(2ll*(f[n+1]+f[m+1]-1)%mod);
	return 0;
}
