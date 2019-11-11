#include<bits/stdc++.h>
typedef long long LL;
typedef double db;
#define REP(i,s,t) for(register int i=s;i<=t;++i)
#define PER(i,s,t) for(register int i=s;i>=t;--i)
#define FOREDGE(i,x,v) for(int i=fir[x],v=to[i];i;i=nex[i],v=to[i])
template<typename T>inline T in(){
    T ans=0;bool b=0;char ch=getchar();
    while(ch<'0'||ch>'9')b=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
    return b?-ans:ans;
}
#define II in<int>()
#define IL in<LL>()
//<-----QAQ----->

int t;
int main(){
	t=II;
	while(t--)puts(std::__gcd(II,II)==1?"Finite":"Infinite");
}