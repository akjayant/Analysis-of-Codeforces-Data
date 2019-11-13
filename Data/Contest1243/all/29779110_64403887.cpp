#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const ll inf=1e18;
/*ll power(ll x,ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return res;
}*/
ll arr[1000001]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t1;
    cin>>t1;
    while(t1--)
    {
        ll n,i,j,a,b,c,r,k,f=0;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<pair<char,ll> >v1,v2;
        vector<pair<ll,ll> >ans;
        unordered_map<char,ll>mp;
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
               v1.pb({s[i],i+1});
               v2.pb({t[i],i+1});
               mp[s[i]]++,mp[t[i]]++;
            }
        }
        for(i=0;i<=25;i++)
        {
            char ch=97+i;
            if(mp[ch]%2!=0)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            cout<<"No"<<endl;
            continue;
        }
        for(i=0;i<v1.size();i++)
        {
            if(v1[i].ff==v2[i].ff)
                continue;
            f=0;
                for(j=i+1;j<v1.size();j++)
                {
                    if(v1[j].ff==v1[i].ff)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1)
                {
                    ans.pb({v1[j].ss,v2[i].ss});
                    v1[j].ff=v2[i].ff;
                    v2[i].ff=v1[i].ff;
                    continue;
                }
                for(j=i+1;j<v2.size();j++)
                {
                    if(v2[j].ff==v1[i].ff)
                    {
                        break;
                    }
                }
                ans.pb({v1[j].ss,v2[j].ss});
                swap(v1[j],v2[j]);
                ans.pb({v1[j].ss,v2[i].ss});
                v1[j].ff=v2[i].ff;
                v2[i].ff=v1[j].ff;
    }
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
        cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
}
}
