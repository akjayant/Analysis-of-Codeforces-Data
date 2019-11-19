#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define deci(n) cout << fixed << setprecision(n);
#define mk make_pair
#define pb push_back
#define pp(a, b) pair <a, b>
#define ll long long int
#define ld long double
#define all(a) a.begin(), a.end()
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> T printr(T p){ cout << p << '\n'; return 0; }
template <class T> T printe(T p){ cout << p << '\n'; exit(0); }
template <class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
const ll INF = (ll)(8e18);
const ll MOD = 1e9 + 7;

const int maxn = 100010;

ll a[maxn];

int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll y = n / 2 + (n % 2);
    ll vala = 0, valb = 0, ans = 0;
    for(ll i = 1; i <= (n - y); i++) vala += a[i];
    for(ll i = (n - y + 1); i <= n; i++) valb += a[i];
    ans = valb * valb + vala * vala;
    cout << ans << '\n';
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}