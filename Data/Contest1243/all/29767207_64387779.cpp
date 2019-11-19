#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll p[100];

void GetP()
{
    ll x=n;
    for(ll i=2;i*i<=x&&i<=n;i++)
    {
        if(n%i==0)
        {
           p[++p[0]]=i;
           while(n%i==0) n/=i; 
        }
    }
    if(n==x) return;
    if(n!=1) p[++p[0]]=n;
}

int main()
{
    scanf("%lld",&n);
    GetP();
    if(p[0]==0)
    {
        printf("%I64d\n",n);
    }
    else if(p[0]==1) printf("%I64d\n",p[1]);
    else printf("1\n");
    return 0;
}