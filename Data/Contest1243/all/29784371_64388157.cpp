#include <bits/stdc++.h>

using namespace std;

//region debugging

#ifdef LOCAL
#include "debugging.h"
#else
#define to_string(...) 0
#define debug_out(...) 0
#define debug(...) 0
#endif

//endregion debugging

//region typedef abbreviations

using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvpii = vector<vector<pair<int, int>>>;
using ull = unsigned long long;
using ll = long long;
using pll = pair<long long, long long>;
using vl = vector<long long>;
using vpll = vector<pair<long long, long long>>;
using vvl = vector<vector<long long>>;
using vvpll = vector<vector<pair<long long, long long>>>;

//endregion typedef abbreviations

// region rep, trav, all, sz

#define REP(i, a, b) for(remove_reference<decltype((b))>::type i = (a); i < (b); ++i)
#define TRAV(a, x) for(auto& a : (x))
#define ALL(x) begin(x), end(x)
#define rep(i, a, b) for(remove_reference<decltype((b))>::type i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : (x))
#define all(x) begin(x), end(x)


template<typename T>
int sz(T x) {
    return (int) x.size();
}

// endregion rep, trav, all, sz

constexpr ll MOD = 1'000'000'000ll + 7;

/**
 * Author: chilli, SJTU
 * Date: 2019-04-24
 * License: CC0
 * Source: https://github.com/FTRobbin/Dreadnought-Standard-Code-Library
 * Description: Pollard-rho randomized factorization algorithm. Returns prime
 * factors of a number, in arbitrary order (e.g. 2299 -> \{11, 19, 11\}).
 * Time: $O(n^{1/4})$ gcd calls, less for numbers with small factors.
 */


typedef unsigned long long ull;
typedef long double ld;
ull mod_mul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull mod_pow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = mod_mul(b, b, mod), e /= 2)
        if (e & 1) ans = mod_mul(ans, b, mod);
    return ans;
}

ull pollard(ull n) {
    auto f = [n](ull x) { return (mod_mul(x, x, n) + 1) % n; };
    if (!(n & 1)) return 2;
    for (ull i = 2;; i++) {
        ull x = i, y = f(x), p;
        while ((p = __gcd(n + y - x, n)) == 1)
            x = f(x), y = f(f(y));
        if (p != n) return p;
    }
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
    trav(a, A) {   // ^ count trailing zeroes
        ull p = mod_pow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = mod_mul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);


#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ull n;
    cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return 0;
    }
    vector<ull> factors;
    factors = factor(n);
    debug(factors);
    ull g = factors[0];
    for (ull factor: factors) {
        g = gcd(g, factor);
    }
    debug(g);
    cout << g << endl;

    return 0;
}
