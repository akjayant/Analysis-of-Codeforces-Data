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

int main() {
    string s;cin >> s;
    int n = s.size();
    REP(i,n) {
        if (s[i] == 'm' || s[i] == 'w') {
            puts("0");
            return 0;
        }
    }
    // dp[i] : i番目まででの値
    vector<mint<MOD>> dp(n+1,0);
    dp[0] = dp[1] = 1;
    FOR(i,1,n) {
        if ((s[i] == 'u' && s[i-1] == 'u') || 
            (s[i] == 'n' && s[i-1] == 'n')) {
            dp[i + 1] = dp[i - 1] + dp[i];
        }
        else {
            dp[i + 1] = dp[i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}