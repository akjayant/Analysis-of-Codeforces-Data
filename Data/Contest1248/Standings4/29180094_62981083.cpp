
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll na,nb;
        cin>>na ;
        ll ao=0,aj=0,bo=0,bj=0;
        for(ll i=1;i<=na;i++)
        {
            ll k;
            cin>>k;
            if(k%2==0)ao++;
            else aj++;
        }
        cin>>nb;
        for(ll i=1;i<=nb;i++)
        {
            ll k;
            cin>>k;
            if(k%2==0)bo++;
            else bj++;
        }
        long long ans=0;
        ans=(ao*bo)+(aj*bj);
        cout<<ans<<endl;
    }
    return 0;
}
