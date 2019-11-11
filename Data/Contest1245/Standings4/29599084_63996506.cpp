/* be name khoda */

// #define stream_enable
#define long_enable
#define debug_enable

#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <limits.h>
#include <fstream>
#include <cstring>

using namespace std;

#ifdef stream_enable
#define cin sss
#endif

#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif
typedef long double dbl;

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;

const ll MOD = 1000000007;

const long long BIG = 1446803456761533460LL;
const int Big = 336860180;

#ifdef long_enable
const ll INF = LONG_LONG_MAX;
#else
const ll INF = INT_MAX;
#endif

const ll adj4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const ll adj8[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back

#define print(x) cout << (x) << '\n'
#define print2(x, y) cout << (x) << ' ' << (y) << '\n'
#define print3(x, y, z) cout << (x) << ' ' << (y) << ' ' << (z) << '\n'
#define print4(x, y, z, t) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << '\n'
#define printp(x) cout << "(" << (x).ff << ", " << (x).ss << ")" << '\n'
#define printa(x, n) fori (ja12345, n) { cout << (x)[ja12345] << ' '; } cout << '\n'
#define printap(x, n) fori (ia1234567, n) { cout << "(" << (x)[ia1234567].ff << ", " << (x)[ia1234567].ss << ")" << '\n'; }
#define printaa(x, n, m) fori (iaa123456, n) { fori (jaa123456, m) { cout << (x)[iaa123456][jaa123456] << ' '; } cout << '\n'; }
#define printav(x, n) fori (iaa123477, n) { printv((x)[iaa123477]); }
#define printia(x, n) fori (ja212345, n) { cout << ja212345 << " : " << (x)[ja212345] << '\n'; }

#ifdef debug_enable
#define debug(x) cout << #x << " -> "; print(x)
#define debug2(x, y) cout << #x << ' ' << #y << " -> "; print2(x, y)
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> "; print3(x, y, z)
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> "; print4(x, y, z, t)
#define debugp(x) cout << #x << " -> "; printp(x)
#define debuga(x, n) cout << #x << " -> "; printa(x, n)
#define debugap(x, n) cout << #x << " ->\n"; printap(x, n)
#define debugaa(x, n, m) cout << #x << " ->\n"; printaa(x, n, m)
#define debugav(x, n) cout << #x << " ->\n"; printav(x, n)
#define debugia(x, n) cout << #x << " ->\n"; printia(x, n)
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x, y, z, t)
#define debugp(x)
#define debuga(x, n)
#define debugap(x, n)
#define debugaa(x, n, m)
#define debugav(x, n, m)
#define debugia(x, n)
#endif

#define forifrom(i, s, n) for(ll i = (s); i < (n); ++i)
#define forirto(i, n, e) for(ll i = (n) - 1; i >= (e); --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define Add(a, b) a = (a + (b)) % MOD
#define Mul(a, b) a = (a * (b)) % MOD

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll powMod(ll a, ll b) {
    ll n = 1;
    ll p = a;
    while (b > 0) {
        if (b % 2 == 1) {
            n *= p;
            n %= MOD;
        }
        p *= p;
        p %= MOD;
        b /= 2;
    }
    return n;
}

ll modularInverse(ll a) {
    return powMod(a, MOD - 2);
}

stringstream sss;

// -----------------------------------------------------------------------

const ll maxn = 100010;

void MAIN() {

    ll T;
    cin >> T;
    fori (t, T) {
        ll a, b;
        cin >> a >> b;
        if (gcd(a, b) == 1) {
            print("Finite");
        } else {
            print("Infinite");
        }
    }

}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    sss << R"(
4
10 10
1 10
6 9
7 3
    )";
    MAIN();
    return 0;
}
