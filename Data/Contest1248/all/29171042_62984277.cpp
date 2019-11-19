#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,d,m,cnt2=0,cnt1=0,res1=0,res2=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>d;
            if(d&1)
                cnt2++;
            else
                cnt1++;
        }
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>d;
            if(d&1)
                res1++;
            else
                res2++;
        }
        printf("%lld\n",1ll*(1ll*cnt2*res1+1ll*cnt1*res2));

    }
    return 0;
}
