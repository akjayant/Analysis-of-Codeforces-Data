#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int) (v).size()
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define pb push_back
#define mp make_pair

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int inf = 0x3f3f3f3f;
constexpr ll MOD = 1000000007LL;
constexpr double tol = 1e-8;

void buff() { ios::sync_with_stdio( false ); cin.tie(nullptr); }

long long pow_mod( ll a, ll b ) {
    ll ans = 1LL, mul = a;
    while( b > 0 ) {
        if( b & 1 ) ans = ( ans * mul ) % MOD;
        mul = (mul * mul) % MOD;
        b /= 2LL;
    }
    return ans;
}


int main() 
{
    buff();
    long long n, m;
    cin >> n >> m;
    long long term = (pow_mod(2LL, m) - 1 + MOD) % MOD;
    cout << pow_mod( term, n ) % MOD << endl;
    return 0;
}

