#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

string s;
ll memo[100'005];
ll mod = 1000000000+7;
ll dp(ll at) {
    if(at >= size(s)-1) return 1;
    else {
        if(memo[at] != -1) return memo[at];
        ll ans = dp(at+1);
        if(s[at] == 'u' && s[at+1] == 'u') ans += dp(at+2);
        if(s[at] == 'n' && s[at+1] == 'n') ans += dp(at+2);
        return memo[at] = (ans) % mod;
    }
}

int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    cin >> s;
    ll ok = 1;
    rep(i,0,size(s)) if(s[i] == 'm' || s[i] == 'w') ok = 0;
    if(!ok) {
        cout << 0 << endl;
        return 0;
    }
    cout << dp(0) << endl;
    return 0;
}


