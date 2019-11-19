#include<bits/stdc++.h>
#define db double
#define ll long long
#define ev edge[i].v
#define pb push_back
#define mod 1000000007
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=head[x];i;i=edge[i].next)
using namespace std;

const int N=1e5+5;

ll f[N][2],g[N][2];
 
int main(){
	ll n,m;
	scanf("%I64d%I64d",&n,&m);
	f[1][0]=g[1][0]=2;
	Rep(i,2,n) f[i][1]=f[i-1][0],f[i][0]=(f[i-1][1]+f[i-1][0])%mod;
	Rep(i,2,m) g[i][1]=g[i-1][0],g[i][0]=(g[i-1][1]+g[i-1][0])%mod;
	printf("%I64d\n",(f[n][0]+f[n][1]+g[m][0]+g[m][1]-2+mod)%mod);
	return 0;
}