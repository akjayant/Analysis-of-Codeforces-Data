//by Judge
#include<cstdio>
#include<cstring>
#include<iostream>
#define Rg register
#define fp(i,a,b) for(Rg int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(Rg int i=(a),I=(b)-1;i>I;--i)
#define ll long long
using namespace std;
const int M=2003;
typedef int arr[M];
#ifndef Judge
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){ int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x*f;
} inline int cread(){ char c=getchar();
	while(!isdigit(c)) c=getchar(); return c-48;
} int n,ans,fir,las; arr a;
int main(){ int T=read();
	while(T--){ n=read(),ans=fir=las=0;
		fp(i,1,n){
			a[i]=cread(),ans+=a[i];
			if(!fir&&a[i]) fir=i;
			if(a[i]) las=i;
		}
		if(!ans){
			printf("%d\n",n);
			continue;
		}
		if(n-fir+1>las) ans=(n-fir+1)*2;
		else ans=las*2;
		printf("%d\n",ans);
	} return 0;
}