#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define mod 1000000007
using namespace std;
const int MAXN=200001;
int x,y,f[MAXN],g[MAXN];
int Mod(int x){return ((x%mod)+mod)%mod;}
signed main()
{
    scanf("%I64d%I64d",&x,&y);
    f[1]=2,f[2]=2,g[1]=2,g[2]=4;
	for(int i=3;i<=100000;i++)
	{
        g[i]=g[i-1]+f[i-1];
		g[i]%=mod;
        f[i]=f[i-1]+f[i-2];
		f[i]%=mod;
    }
    int ans1=g[x],ans2=g[y];
    printf("%I64d\n",Mod(ans1-2+ans2));
    return 0;
}