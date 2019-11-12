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

    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ll curans = min(arr[i] , n-i);
        ans = max(ans , curans);
    }

    cout<<ans<<endl;
}

int main()
{
    fio;
    ll t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

}
