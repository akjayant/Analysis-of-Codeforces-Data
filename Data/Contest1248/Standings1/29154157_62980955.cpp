#include<bits/stdc++.h>
#define fp(i,a,b) for(register int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(register int i=a,I=b-1;i>I;--i)
#define go(u) for(int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
template<class T>inline void sd(T&x){
	char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45)y=-1;x=c-48;
	while(c=gc(),47<c&&c<58)x=x*10+c-48;x*=y;
}
const int N=1e5+5;
typedef int arr[N];
typedef long long ll;
int n;arr a;
int main(){
	#ifndef ONLINE_JUDGE
		file("s");
	#endif
	sd(n);
	fp(i,1,n)sd(a[i]);
	sort(a+1,a+n+1);
	int dx=0,dy=0;
	fp(i,1,n/2)
		dy+=a[i],dx+=a[n-i+1];
	if(n&1)dx+=a[n/2+1];
	printf("%lld\n",(ll)dx*dx+(ll)dy*dy);
return 0;
}