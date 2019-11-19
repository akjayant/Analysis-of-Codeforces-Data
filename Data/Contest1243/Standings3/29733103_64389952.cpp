#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pii 3.14
#define mod (ll)(1000000007)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pi pair<int,int>
#define N (ll)(1e6+5)

void solve()
{
    ll n;
    cin>>n;

    vector<ll>v;

    for(ll i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            v.push_back(i);
            if(i*i != n)
                v.push_back(n/i);
        }
    }

    if(v.empty())
    {
        cout<<n<<endl;
        return;
    }

    ll ans = v[0];
    for(ll el : v)
        ans = __gcd(ans , el);

    cout<<ans;


}

int main()
{
    fio;
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

}
