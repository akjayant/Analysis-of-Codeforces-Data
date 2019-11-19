//by Judge
#include<cstdio>
#include<cstring>
#include<iostream>
#define Rg register
#define fp(i,a,b) for(Rg int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(Rg int i=(a),I=(b)-1;i>I;--i)
#define ll long long
using namespace std;
const int inf=1e9+7;
const int M=1e5+3;
typedef int arr[M];
#ifndef Judge
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){ int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x*f;
} ll n,m,a[2],b[2];
inline void Solv(){ Rg int x; a[0]=a[1]=b[0]=b[1]=0;
	n=read(); fp(i,1,n) x=read(),++a[x&1];
	m=read(); fp(i,1,m) x=read(),++b[x&1];
	printf("%lld\n",a[0]*b[0]+a[1]*b[1]);
}
int main(){ int T=read();
	while(T--) Solv(); return 0;
}