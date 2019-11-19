#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned ll
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair<ll, ll>
#define mt make_tuple
#define mn(a, b) a = min(a, b)
#define mx(a, b) a = max(a, b)
 
using namespace std;
 
const ll INF = (ll)2e9;
const ll inf = (ll)2e18;
const ld eps = (ld)1e-6;
const ll mod = (ll)1e9 + 7;
const ll MAXN = (ll)1e6;
const ll MAXC = (ll)6e6;
const ll MAXLOG = 65;
const ll maxlen = (ll)1e5;
const ll asci = (ll)256;
const ll block = 707;
//
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
 
template <class T>
istream& operator >>(istream &in, vector<T> &arr){
     for (T &cnt : arr) {
        in >> cnt;
    }
    return in;
};
 
void solve() {
    ll n, k; cin >> n >> k;
    vi a(n); cin >> a;
    sort(all(a));
    int l = 0, r = n - 1;
    while (r > l) {
        if (a[l] == a[l + 1]) {l++; continue;}
        if (a[r] == a[r - 1]) {r--; continue;}
        if (l <= n - 1 - r) {
            if (k >= (l + 1) * (a[l + 1] - a[l])) k -= (l + 1) * (a[l + 1] - a[l]);
            else cout << a[r] - a[l] - k / (l + 1), exit(0);
            l++;
        } else {
            if (k >= (n - r) * (a[r] - a[r - 1])) k -= (n - r) * (a[r] - a[r - 1]);
            else cout << a[r] - k / (n - r) - a[l], exit(0);
            r--;
        }
    }
    cout << 0 << "\n";
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cout.precision(30);
    solve();
 
    return 0;
}