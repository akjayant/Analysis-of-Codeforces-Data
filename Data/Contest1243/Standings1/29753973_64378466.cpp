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
        vector<ll> idx;
        for(ll i=0;i<n;++i)
        {
            if(s[i]!=t[i]){idx.pb(i);}
        }
        if(idx.size()!=2){
            cout<<"No"<<endl;continue;
        }
        ll i1=idx[0],i2=idx[1];
        if(s[i1]==s[i2]&&t[i1]==t[i2])
        {
            cout<<"Yes"<<endl;
        }
        else{cout<<"No"<<endl;}
    }

    return (0);
}
