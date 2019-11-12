#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    scanf("%lld",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%lld",&n);
        vector<ll>vec;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            vec.push_back(a);
        }
        sort(vec.rbegin(),vec.rend());
        x=0;
        for(i=0;i<n;i++)
        {
            y=min(i+1,vec[i]);
            x=max(x,y);
        }
        printf("%lld\n",x);
    }
}
