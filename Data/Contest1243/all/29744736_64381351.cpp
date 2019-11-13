#include <bits/stdc++.h>
#define pb push_back
#define sc1(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
#define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define MX 100000
#define PI acos(-1)
#define block 320
using namespace std;

typedef long long int ll;

int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<ll>vs;
        for(ll i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                vs.pb(i);
            }
        }
        if(vs.size()!=2)
        {
            cout<<"No"<<endl;
        }
        else
        {
            ll a=vs[0];
            ll b=vs[1];
            if(s[a]==s[b]&&t[a]==t[b])
            {
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
    }

    return 0;
}
