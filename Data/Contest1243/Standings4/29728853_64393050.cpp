#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//namespaces
using namespace __gnu_pbds; 
using namespace std;

//MACROS
#define ld long double
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define watch(x) cout << "debug : " << #x << " -> " << x << endl; 
#define For(i,s,e) for (int i=(s); i<(e); i++)
#define Fod(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define pii pair<ll,ll>
#define f first
#define s second
#define endl "\n"

//Templates
template <typename T>
using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }

//globals
ll const mod = 1e9+7;
ll const inf = 1e18;
ll const size_1d = 1e6 + 7;
ll const size_2d = 1e3 + 7;

//functions
ll power(ll x, ll y, ll mod = 2e18){ ll ans = 1;x %= mod;while(y){if(y&1)ans = (x * ans) % mod;x = (x * x) % mod;y >>= 1;}return ans;}
ll modInverse(ll a, ll m){ll m0 = m;ll y = 0, x = 1;if (m == 1) return 0;while (a > 1){ ll q = a / m;ll t = m;m = a % m,a = t;t = y;y = x - q * y;x = t;}if(x < 0) x += m0;return x;} 
ll gcdext(ll a,ll b,ll *x = 0, ll *y = 0){if(a == 0){*x = 0;*y = 1;return b;}ll x1,y1;ll gcd1 = gcdext(b%a,a,&x1,&y1);*x = y1 - (b/a)*x1;*y = x1;return gcd1;}
int randomize(){return (rand()%10000);} 

// CODE STARTS HERE


int main(){
    IOS

    ll n;cin >> n;
    ll x,y;
    if(n == 1) return cout << 1 << endl,0;
    ll k = -1;
    for (ll i = 2; i < 1ll*(sqrt(n) + 10); ++i)
    {
        if(n%i == 0){
            if(k == -1) k = i;
            else k = gcdext(i,k,&x,&y);
            while(n%i == 0){
                n /= i;
            }
        }
    }
    if(n != 1){
        if(k == -1)
            k = n;
        else
            k = gcdext(k,n,&x,&y);
    }
    cout << k << endl;
    return 0;
}