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
const ld eps = (ld)1e-8;
const ll mod = (ll)1e9 + 7;
const ll MAXN = (ll)100;
const ll MAXC = (ll)1e6 + 1;
const ll MAXE = (ll)2000;
const ll MAXLOG = 19;
const ll maxlen = (ll)1e5;
const ll asci = (ll)256;
const ll block = 50000;
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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt = 0;
    vi sw;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {cnt++; sw.push_back(i);};
    }
    if (cnt && cnt != 2) {cout << "No\n"; return;}
    if (!cnt) {cout << "Yes\n"; return;}
    swap(s[sw[0]], t[sw[1]]);
    if (s == t) {cout << "Yes\n"; return;}
    cout << "No\n";
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
    cout.precision(50);
    int t; cin >> t;
    while(t--)
    solve();
 
    return 0;
}