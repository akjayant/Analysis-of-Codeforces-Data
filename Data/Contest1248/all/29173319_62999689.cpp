#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

template<int mod>
struct mint {
private:
    long long x;
public:
    mint(long long x = 0) :x(x%mod) {}
    mint(std::string s) {
        long long z = 0;
        REP(i, s.size()) {
            z *= 10;
            z += s[i] - '0';
            z %= mod;
        }
        this->x = z;
    }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& n) {
        return os << n.x;
    }
    bool operator==(const mint a) const {
        return this->x == a.x;
    }
};

mint<MOD> memo[100005];
bool p[100005];

mint<MOD> solve(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (p[n]) return memo[n];
    memo[n] = solve(n - 2) + solve(n - 1);
    p[n] = true;
    return memo[n];
}

int main() {
    int n, m; cin >> n >> m;
    cout << (solve(n) + solve(m) - 1) * 2 << endl;
    return 0;
}