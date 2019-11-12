#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define MX LLONG_MAX
#define MN LLONG_MIN

const ll mod=1e9+7;
const ll N=1e3+5;

ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
ll power(ll _a,ll _b){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}          
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

int32_t main()                  
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<pair<ll,ll> > ans;
        set<ll> arr[26],brr[26];
        for(ll i=0;i<n;i++)
        {
            arr[a[i]-'a'].insert(i);
            brr[b[i]-'a'].insert(i);
        }
        ll flag = 1;
        for(ll i=0;i<n;i++)
        {
            //cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
            //cout<<arr[a[i]-'a'].size()<<" - "<<brr[b[i]-'a'].size()<<endl;
            if(a[i]==b[i])
            {
                arr[a[i]-'a'].erase(i);
                brr[b[i]-'a'].erase(i);
                continue;
            }
            if(arr[a[i]-'a'].size() > 1)
            {
                arr[a[i]-'a'].erase(i);
                
                auto it = arr[a[i]-'a'].begin();
                ll ind = *it;
                //cout<<" - "<<ind<<endl;
                arr[a[i]-'a'].erase(ind);
                brr[b[i]-'a'].erase(i);
                
                arr[b[i]-'a'].insert(ind);
                
                ans.pb({ind,i});
                swap(a[ind],b[i]);
            }
            else if(brr[a[i]-'a'].size() > 0)
            {
                auto it = brr[a[i]-'a'].begin();
                ll ind = *it;
                
                //cout<<" -- "<<ind<<endl;
                
                brr[a[i]-'a'].erase(ind);
                
                arr[a[ind]-'a'].erase(ind);
                brr[a[ind]-'a'].insert(ind);
                
                brr[b[i]-'a'].erase(i);
                arr[b[i]-'a'].insert(ind);
                arr[a[i]-'a'].erase(i);
                
                ans.pb({ind,ind});
                swap(a[ind],b[ind]);
                ans.pb({ind,i});
                swap(a[ind],b[i]);
            }
            else
            {
                flag = 0;
                break;
            }
            //cout<<a<<endl<<b<<endl;
        }
        if(flag && ans.size() <= 2*n)
        {
            cout<<"Yes"<<endl;
            cout<<ans.size()<<endl;
            for(ll i=0;i<ans.size();i++)
            {
                cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
            }
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
