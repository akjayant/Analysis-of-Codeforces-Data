#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline ll read()
{
    ll ret=0,flag=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')flag=-1;c=getchar();}
    while(c>='0'&&c<='9')ret=ret*10+(c^'0'),c=getchar();
    return flag*ret;
}

const ll N=1e5+5;
ll n;
ll s[N];

int main()
{
    n=read();
    for(ll i=1;i<=n;i++)s[i]=read();
    sort(s+1,s+n+1);
    ll sum1=0,sum2=0;
    for(ll i=1;i<=(n>>1);i++)
        sum1+=s[i];
    for(ll i=(n>>1)+1;i<=n;i++)
        sum2+=s[i];
    printf("%lld\n",sum1*sum1+sum2*sum2);
    return 0;
}
