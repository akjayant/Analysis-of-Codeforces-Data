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
        vector<pair<ll,ll>>V;
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll cnt[30]= {0};
        for(ll i=0; i<n; i++)
        {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        ll ok=1;
        for(ll i=0; i<26; i++)
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
        for(ll i=0; i<n; i++)
        {
            if(s[i]==t[i])
                continue;
            ll id=-1;
            for(ll j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                {
                    id=j;
                    break;
                }
            }
            if(id!=-1)
            {
                V.pb({id,i});
                swap(s[id],t[i]);
                continue;
            }
            for(ll j=i+1;j<n;j++)
            {
                if(t[j]==t[i])
                {
                    id=j;
                    break;
                }
            }
            if(id!=-1)
            {
                V.pb({i,id});
                swap(s[i],t[id]);
                continue;
            }
            for(ll j=i+1;j<n;j++)
            {
                if(s[i]==t[j])
                {
                    id=j;
                    break;
                }
            }
            swap(s[i+1],t[id]);
            swap(s[i+1],t[i]);
            V.pb({i+1,id});
            V.pb({i+1,i});
        }
        printf("Yes\n");
        ll sz=V.size();
        printf("%lld\n",sz);
        for(ll i=0;i<sz;i++)
        {
            printf("%lld %lld\n",V[i].first+1,V[i].second+1);
        }
    }
    return 0;
}
