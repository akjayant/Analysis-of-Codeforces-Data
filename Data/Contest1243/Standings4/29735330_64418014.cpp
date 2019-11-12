#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll md=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long q=1;
    cin>>q;
    while(q--)
    {
        ll n; bool kt=1; string s,t;
        vector<pii> a;
        vector<vector<ll>> dd(26,vector<ll>(2,0));
        cin>>n;
        cin.ignore();
        getline(cin,s);
        getline(cin,t);
        for(ll i=0;i<n;++i)
        {
            dd[int(s[i]-'a')][0]++;
            dd[int(t[i]-'a')][1]++;
        }
        for(ll i=0;i<26;++i)
        {
            if((dd[i][0]+dd[i][1])%2==1) {cout<<"NO"<<endl;kt=0;break;}
        }
        if(kt)
        {
            cout<<"YES"<<endl;
            for(ll i=0;i<n;++i)
            {
                if(s[i]==t[i]) continue;
                for(ll j=i+1;j<n;++j)
                {
                    if(s[i]==s[j])
                    {
                        a.push_back(pii(j+1,i+1));
                        s[j]=t[i];t[i]=s[i];
                        break;
                    }
                    if(s[i]==t[j])
                    {
                        a.push_back(pii(j+1,j+1));
                        a.push_back(pii(j+1,i+1));
                        t[j]=s[j];s[j]=t[i];
                        break;
                    }
                }
            }
            cout<<a.size()<<endl;
            for(ll i=0;i<a.size();++i)
            {
                cout<<a[i].first<<' '<<a[i].second<<endl;
            }
        }
    }
    return 0;
}
