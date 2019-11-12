#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define frac pair<ll, ll>
#define t_trials for (cin >> _; _; _--)
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define N 200005
const ll inf = 1e9 + 7;
ll arr[N];
ll n, m, k, t, t1, t2, t3, t4, t5, t6, _;
string s;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> t1>> t2 >> t3;
        ll ans = min(t2, t3/2);
        t2-=ans;
        t3-=ans;
        ans+=min(t1, t2/2);
        cout << ans*3 << endl;
    }
    return 0;
}