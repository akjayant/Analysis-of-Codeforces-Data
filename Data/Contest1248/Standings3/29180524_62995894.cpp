#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dwn(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int mod=1000000007;
int n,m,a[100010];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    n=read(),m=read();
    a[1]=2,a[2]=4;
    for(int i=3;i<=max(n,m);++i) a[i]=(a[i-1]+a[i-2])%mod;
    printf("%d\n",((a[n]+a[m]-a[1])%mod+mod)%mod);
    return 0;
}
