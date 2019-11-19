#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
const int N=100000+10;
const int mod=1e9+7;
int n,m;
int f[N];
signed main(){
    scanf("%d%d",&n,&m);
    f[0]=f[1]=1;
    for(int i=2;i<=max(n,m);i++)
        f[i]=(f[i-1]+f[i-2])%mod;
    printf("%d",(f[m]+f[n]-1)%mod*2%mod);
    return 0;
}