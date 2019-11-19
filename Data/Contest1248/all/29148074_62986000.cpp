#include<bits/stdc++.h>
using namespace std;
#define N 200003
#define LL long long
#define mod 1000000007

int n,m,ans;
int g[N];

inline int read(){
	int X=0,w=0;
	char ch=0;
	while (ch<'0' || ch>'9')
	  w|=ch=='-',ch=getchar();
	while (ch>='0' && ch<='9')
	  X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w ? -X : X;
}

int main(){
	n=read();m=read();
	g[1]=1;g[2]=2;
	for (int i=3;i<=max(n,m);i++)
	  g[i]=(g[i-1]+g[i-2])%mod;
	ans=1ll*g[n]*2%mod;
	ans=(ans-2+mod)%mod;
	ans=(ans+1ll*2*g[m]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}