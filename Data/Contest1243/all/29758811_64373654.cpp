#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define ll long long
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define PB push_back
using namespace std;
using namespace __gnu_pbds;

const ll N = 3e5 + 200;
const ll MOD = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll Q,n,a[N],ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>Q;
    while(Q--)
    {
        cin>>n;
        for(int i = 1; i <= n; i++) cin>>a[i];
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        ans = 0;
        for(ll i = 1; i <= n; i++)
        {
            ans = max(ans, min(i, a[i]));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
