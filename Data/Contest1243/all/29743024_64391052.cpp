#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;


int main()
{
    ll n,ans=0,tmp=0,pp;
    cin>>n;
    pp=n;
    for(ll i=2;i*i<=pp;i++)
    {
        if(pp%i==0)
        {
            ans++;
            tmp=i;
            while(pp%i==0)pp/=i;
        }
    }
    if(!ans)printf("%lld",n);
    else if(ans>=2)printf("1");
    else
    {
        if(pp>1)
        {
            printf("1");
        }
        else printf("%lld",tmp);
    }
    return 0;
}
