//C. Ivan the Fool and the Probability Theory
//By: Terrasse
//2019年 10月 20日 星期日 17:50:10 CST

#include<iostream>
#define int long long
#define MAXN 100011
#define H 1000000007
using namespace std;
int f[MAXN],n=0,m=0;
signed main()
{
    register int i=0;
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    if(n<m)
    {
        n^=m^=n^=m;
    }
    for(f[1]=1,f[2]=2,i=3;i<=n;++i)
    {
        f[i]=(f[i-1]+f[i-2])%H;
    }
    cout<<(f[n]+f[m]+H-1)*2%H<<endl;
    return 0;
}
