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
int a[N];
int main(){
	int n=ci();
	rep(i,1,n) a[i]=ci();
	sort(a+1,a+n+1);
	ll a1=0, a2=0;
	int m=n/2;
	rep(i,1,m) a1+=a[i];
	rep(i,m+1,n) a2+=a[i];
	ptll(a1*a1+a2*a2);
	return 0;
}
