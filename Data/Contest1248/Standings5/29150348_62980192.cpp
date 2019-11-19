#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+5;
ll quick(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
ll n,a[maxn];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=n/2)sum1+=a[i];
        else sum2+=a[i];
    }
    cout<<sum1*sum1+sum2*sum2<<endl;
    return 0;
}
