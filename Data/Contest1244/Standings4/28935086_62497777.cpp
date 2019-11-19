#include <bits/stdc++.h> 
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); }
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd((a), (b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int main() 
{
    ll n,k;
    cin>>n>>k;
    map <ll,ll> m;
    vector <ll> v;
    ll p=0;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        m[temp]++;
        if(m[temp]==1)
        {
            v.pb(temp);
            p++;
        }
    }
    sort(all(v));
    ll l=0;
    ll h=p-1;
    ll ans=v[h]-v[l];
    while(k>0)
    {
        if(m[v[l]]<=m[v[h]])
        {
            ll t = v[l+1] - v[l];
            if((t*m[v[l]])<=k)
            {
                k=k-(t*m[v[l]]);
                ans=ans-t;
                m[v[l+1]]=m[v[l+1]]+m[v[l]];
                l++;
            }
            else
            {
                ans=ans-(k/m[v[l]]);
                k=0;
            }
        }
        else
        {
            ll t = v[h] - v[h-1];
            if((t*m[v[h]])<=k)
            {
                k=k-(t*m[v[h]]);
                ans=ans-t;
                m[v[h-1]]=m[v[h-1]]+m[v[h]];
                h--;
            }
            else
            {
                ans=ans-(k/m[v[h]]);
                k=0;
            }
        }
    }
    if(ans<0)
        ans=0;
    cout<<ans<<endl;
    return 0;
}