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
ll t,n,m,tmp,sum1,sum2,sum3,sum4;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        sum1=sum2=sum3=sum4=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tmp;
            if(tmp%2==0)sum1++;
            else sum2++;
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>tmp;
            if(tmp%2==0)sum3++;
            else sum4++;
        }
        ll sum=sum1*sum3+sum2*sum4;
        cout<<sum<<endl;
    }
    return 0;
}
