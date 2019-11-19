#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll p[n];
        ll e1=0,o1=0,e2=0,o2=0;
        for(int i=0;i<n;i++)   
        {
            cin>>p[i];
            if(p[i]%2==0)
                e1++;
            else
                o1++;
        }
        ll m;
        cin>>m;
        ll q[m];
        for(int i=0;i<m;i++)
        {
            cin>>q[i];
            if(q[i]%2==0)
                e2++;
            else
                o2++;
        }
        
        ll ans=0;
        ans=ans+e1*e2+o1*o2;
        cout<<ans<<endl;
        
    }
    return 0;
}
