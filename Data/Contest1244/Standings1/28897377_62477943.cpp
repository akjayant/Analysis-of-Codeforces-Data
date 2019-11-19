#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,p,w,d,i;
    cin>>n>>p>>d>>w;
    if(n*d<p)
    {
        printf("-1\n");
        return 0;
    }
    ll x=p/d;
    for(i=x;i>=x-100000;i--)
    {
        if(i<0)break;
        if((i+(p-i*d)/w)>n)break;
        if((p-i*d)%w==0)
        {
            printf("%lld %lld %lld\n",i,(p-i*d)/w,n-i-(p-i*d)/w);
            return 0;
        }
    }
    printf("-1\n");
}
