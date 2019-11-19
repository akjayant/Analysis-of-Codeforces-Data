#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define hi cout<<'h'<<'i'<<'\n' 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    int i,j,t;
    boost;
    ll n;
    cin>>n;

    vector<ll> div;
    ll h;
    for(h=2;h*h<=n;h++)
    {
        if(n%h==0)
        {
            div.pb(h);
            ll k=n/h;
            if(k!=h)div.pb(k);
        }
    }
    if(div.empty())cout<<n;
    else
    {
        ll g=div[0];
        rep(i,1,sz(div))
        {
            g=__gcd(g,div[i]);
        }
        
        cout<<g;

    }
    return 0;
}

