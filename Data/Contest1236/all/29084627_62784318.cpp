#include <math.h>
#include <assert.h>

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

template <typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& v) {
    return is >> v.first >> v.second;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (T& i: v) {
        is >> i;
    }
    return is;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v) {
    return os << v.first << " " << v.second;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    int n = (int) v.size();
    for (int i = 0; i < n; ++i) {
        os << v[i] << (i == n - 1 ? "" : " ");
    }
    return os;
}

template <typename X>
void in(X& x) {
    std::cin >> x;
}

template <typename X, typename Y>
void in(X& x, Y& y) {
    in(x); in(y);
}

template <typename X, typename Y, typename Z>
void in(X& x, Y& y, Z& z) {
    in(x); in(y, z);
}

template <typename X, typename Y, typename Z, typename W>
void in(X& x, Y& y, Z& z, W& w) {
    in(x); in(y, z, w);
}

template <typename T>
void out(const T H) {
    std::cout << (H);
}

template <typename T1, typename... T2>
void out(const T1 H, const T2... T) {
    std::cout << (H) << " "; out(T...);
}

template <typename T>
void eout(const char *s, const T H) {
    std::cerr << s << "=" << H << "\n";
}

template <typename T1, typename... T2>
void eout(const char *s, const T1 H, const T2... T) {
    while (*s != ',') std::cerr << *s++;
    std::cerr << "=" << H << " | "; eout(++s, T...);
}

#define nl                std::cout << "\n"

#ifdef LOCAL
#define err(args...)      eout(#args, args)
#else
#define err(args...)      42
#endif

#define rep(i, n)         for (int i =  0 ; i < (n); ++i)
#define per(i, n)         for (int i = (n) - 1; i > -1; --i)
#define repr(i, l, r)     for (int i = (l); i < (r); ++i)

#define sz(v)             ((int) v.size())
#define all(v)            (v).begin(), (v).end()
#define lla(v)            (v).rbegin(), (v).rend()

#define no                std::cout << "NO\n"
#define yes               std::cout << "YES\n"

const int INF           = 2147483647;
const long long int LNF = 9223372036854775807LL;

using ll  = long long int;
using vl  = std::vector<ll>;
using vi  = std::vector<int>;
using vb  = std::vector<bool>;
using ii  = std::pair<int, int>;
using iii = std::pair< ii, int>;
using vii = std::vector<ii>;

const int N  = 505050;
const int MD = 1000*1000*1000 + 7;

int solve();
int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t; in(t); repr(tc, 1, t + 1)
    solve();

    return 0;
}

int solve() {
    int a, b, c;
    in(a, b, c);

    int ans = 0;
    for (int o1 = 0; o1 <= a; ++o1) {
        for (int o2 = 0; 2*o2 <= c; ++o2) {
            if (2*o1 + o2 <= b) {
                ans = std::max(ans, o1 + o2);
            }
        }
    }
    out(ans*3), nl;
    return 0;
}
