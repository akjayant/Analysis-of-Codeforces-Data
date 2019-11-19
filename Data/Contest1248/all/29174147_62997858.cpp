#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define mod 1000000007
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=200001;
int x,y,f[MAXN],g[MAXN];
int Mod(int x){return ((x%mod)+mod)%mod;}
signed main(){
	x=read(),y=read();
	f[1]=2,f[2]=2,g[1]=2,g[2]=4;for(int i=3;i<=100000;i++){
		g[i]=g[i-1]+f[i-1];g[i]%=mod;
		f[i]=f[i-1]+f[i-2];f[i]%=mod;
	}
	int Ans1=g[x],Ans2=g[y];
	printf("%lld\n",Mod(Ans1-2+Ans2));
	return 0;
}
