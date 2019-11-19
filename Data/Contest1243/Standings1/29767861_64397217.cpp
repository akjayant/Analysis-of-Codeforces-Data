#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e9+7

int main()
{
    ll n;
    cin>>n;
    vector<ll>v;
    ll ans=-1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(ans==-1)
                ans=i;
            while(n%i==0)
            {
                n/=i;
            }
            v.push_back(i);
        }
    }
    if(n>1)
        v.push_back(n);
    int m=v.size();
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(__gcd(i,j)==1)
            {
                cout<<1<<"\n";
                return 0;
            }
        }
    }
    if(ans==-1)
        ans=n;
    cout<<ans<<endl;
    return 0;
}
