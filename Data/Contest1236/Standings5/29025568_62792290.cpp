#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long mul_mod(long long a, long long b, long long m) {
    long long ans = 0;
    a %= m;
    b %= m;

    while (b) {
        if (b & 1ll) {
            ans = ans + a;
            if (ans >= m)
                ans -= m;
        }
        a <<= 1;
        if (a >= m)
            a -= m;
        b >>= 1;
    }

    return ans;
}

long long pow_mod(long long a, long long n, long long m) {
    long long ans = 1;

    while (n) {
        if (n & 1) {
            ans = mul_mod(ans, a, m);
        }
        n >>= 1;
        a = mul_mod(a, a, m);
    }

    return ans;
}

long long mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;

    long long ans = (pow_mod(2ll, m, mod) + mod - 1) % mod;
    // cout << ans << endl;
    ans = pow_mod(ans, n, mod);
    cout << ans << endl;
    return 0;
}
