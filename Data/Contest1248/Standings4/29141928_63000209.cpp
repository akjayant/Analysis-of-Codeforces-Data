#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 1000000007
#define maxx 100005
using namespace std;
struct M
{
    ll a[4][4];
    M mul(M x)
    {
        M ans;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                ans.a[i][j]=0;
                for(int k=0;k<4;k++)
                {
                    ans.a[i][j]+=a[i][k]*x.a[k][j]%mod;
                    if(ans.a[i][j]>=mod)ans.a[i][j]-=mod;
                }
            }
        return ans;
    }
};
M P(M a,int b)
{
    M ans;
    memset(ans.a,0,sizeof(ans.a));
    for(int i=0;i<4;i++)ans.a[i][i]=1;
    while(b)
    {
        if(b&1)ans=ans.mul(a);
        a=a.mul(a);
        b>>=1;
    }
    return ans;
}
int n,m;
int main()
{
    cin>>n>>m;
    M U;
    memset(U.a,0,sizeof(U.a));
    U.a[0][2]=1;
    U.a[1][0]=U.a[1][2]=1;
    U.a[2][1]=U.a[2][3]=1;
    U.a[3][1]=1;
    M A=U;
    ll ans=0;
    if(n>=3)
    {
        M res=P(A,n-2);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                ans+=res.a[i][j];
                if(ans>=mod)ans-=mod;
            }
        }
    }
    else
    {
        if(n==1)ans+=2;
        else ans+=4;
    }
    A=U;
    if(m>=3)
    {
        M res=P(A,m-2);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                ans+=res.a[i][j];
                if(ans>=mod)ans-=mod;
            }
        }
    }
    else
    {
        if(m==1)ans+=2;
        else ans+=4;
    }
    ans-=2;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
    return 0;
}