#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
 
#define ll long long
#define ld long double
 
#define pb push_back
#define ins insert
#define er erase
 
#define f(i, a, b) for (i = a; i < b; ++i)
#define rf(i, a, b) for (i = a; i >= b; --i)
 
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define vst vector<string>
#define vpii vector<pii>
#define vpll vector<pll>
 
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define mxe max_element
#define mne min_element
 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
 
#define bs bitset
#define bpc(a) __builtin_popcount(a)
 
#define mii map<int, int>
#define mll map<ll, ll>
#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
 
#define pqi priority_queue<int>
#define pqll priority_queue<ll>
 
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*1ll * (b)) / gcd(a, b)
 
#define nl "\n"
#define sp " "
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
#define ok order_of_key
#define fo find_by_order
 
ll md = 1000 * 1000 * 1000 + 7 ;
 
ll pw(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
 
ll modinv(ll n)
{
    return pw(n, md - 2);
}
 
ll my_ceil(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}
 
inline ll add(ll a, ll b) { return (md + a + b) % md; }
inline ll subt(ll a, ll b) { return (a - b + md) % md; }
inline ll mult(ll a, ll b) { return (1ll * a * b) % md; }
 
//LET'S PLAY THE GAME!!
 
int main()
{
    fast;
 
    int n, m, i, j, e, x, k, l, r, q ;
    
    cin >> n >> m ;
    e = max(n, m) ;
    ll dp[e + 1] ;
    dp[0] = 1 ; 
    f(i, 1, e + 1) {
        if(i == 1) dp[i] = dp[i - 1] ;
        else dp[i] = add(dp[i - 1] , dp[i - 2]) ; 
    }
    cout << mult(2, subt(add(dp[n], dp[m]),1)) ;
 
    return 0;
}
 
// AND THE GAME IS OVER !!