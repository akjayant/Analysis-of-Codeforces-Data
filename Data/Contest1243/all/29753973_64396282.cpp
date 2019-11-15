#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=200010;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll ar[26]={0};
        for(ll i=0;i<n;++i)
        {
            ++ar[s[i]-'a'];
            ++ar[t[i]-'a'];
        }
        int f=1;
        for(ll i=0;i<26;++i)
        {
            if(ar[i]%2==1){f=0;}
        }
        if(f==0){cout<<"No"<<endl;continue;}
        vector<pi> ans;
        for(ll i=0;i<n;++i)
        {
            if(s[i]==t[i]){continue;}
            ll idx;
            for(idx=i+1;idx<n;++idx)
            {
                if(s[idx]==s[i]){break;}
            }
            if(idx<n)
            {
                swap(t[i],s[idx]);
                ans.pb(mp(idx+1,i+1));
                continue;
            }
            for(idx=i+1;i<n;++idx)
            {
                if(t[idx]==s[i]){break;}
            }
            if(idx==n){exit(1);}
            swap(s[n-1],t[idx]);
            ans.pb(mp(n,idx+1));
            swap(s[n-1],t[i]);
            ans.pb(mp(n,i+1));
        }
        if(s!=t){cout<<"No"<<endl;continue;}
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();++i)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }

    return (0);
}
