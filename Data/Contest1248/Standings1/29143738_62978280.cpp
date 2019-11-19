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


int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll onen = 0, onem = 0;
        for(ll i = 0; i < n; i++){
            ll x; cin >> x;
            if(x % 2 == 0) onen++;
        }
        ll m; cin >> m;
        for(int i = 0; i < m; i++){
            ll x; cin >> x;
            if(x % 2 == 0) onem++;
        }
        cout << onen * onem + (n - onen) * (m - onem) << '\n';
    }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}