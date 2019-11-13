#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[10000];

int main()
{
    ll a,b,c,x,y,z;
    ll test,t,i,j,k,n;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&ara[i]);
        }
        z=0;
        sort(ara+1,ara+n+1);
        for(i=n,j=1;i>0;i--,j++)
        {
            x=min(j,ara[i]);
            z=max(z,x);
        }
        cout<<z<<endl;
    }
}
