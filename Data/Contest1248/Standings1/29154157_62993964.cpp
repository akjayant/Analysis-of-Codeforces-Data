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
const int N=1e5+5,Mod=1e9+7;
typedef int arr[N];
typedef long long ll;
int n,m,ans;arr f;
inline int Plus(int a,int b){return a+=b,a>Mod?a-Mod:a;}
int main(){
	#ifndef ONLINE_JUDGE
		file("s");
	#endif
	sd(n),sd(m);
	if(n<m)swap(n,m);
	f[0]=f[1]=2;
	fp(i,2,n)f[i]=Plus(f[i-1],f[i-2]);
	ans=f[n];
	fp(i,2,m)ans=Plus(ans,f[i-2]);
	printf("%d",ans);
return 0;
}