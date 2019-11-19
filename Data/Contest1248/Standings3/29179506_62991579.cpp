#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=1e5+50;
const int mod=1e9+7;
LL a[maxn];
int main()
{
    LL N,M;cin>>N>>M;
    a[1]=2;a[2]=4;
    for(int i=3;i<=max(N,M);i++) a[i]=(a[i-1]+a[i-2])%mod;
    LL ans=a[M];
    if(N>1) ans+=2;
    for(int i=1;i<N-1;i++) ans=(ans+a[i])%mod;
    cout<<ans<<endl;
    return 0;
}
/**

*/
