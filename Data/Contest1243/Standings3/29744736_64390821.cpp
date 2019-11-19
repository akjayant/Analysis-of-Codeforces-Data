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
vector<ll>V;
int main()
{
    ll n;
    sc1(n);
    ll m=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            V.pb(i);
            while(n%i==0)
                n=n/i;
        }
    }
    if(n!=1)
        V.pb(n);
    if(V.size()==1)
    {
        cout<<V[0]<<endl;
    }
    else
        cout<<1<<endl;
    return 0;
}
/*
ll test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll cnt[30]={0};
        for(ll i=0;i<n;i++)
        {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        ll ok=1;
        for(ll i=0;i<26;i++)
        {
            if(cnt[i]%2)
            {
                ok=0;
                break;
            }
        }
        if(ok==0)
        {
            cout<<"No"<<endl;
            continue;
        }

    }

    */
