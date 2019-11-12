#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mp make_pair
#ifndef MY
    #define endl '\n'
#endif
#define int long long
#define sz(x) (int)x.size()

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int, int > pii;

ostream & operator << (ostream & out, vector < int > & lst) {
    for (auto a : lst)
        out << a << ' ';
    out << endl;
    return out;
}

const int mod = 1e9 + 7;
struct Int {
    int x;
    Int (int x = 0) : x(x) {};
    Int operator *= (Int a) {
        x *= a.x;
        x %= mod;
        return *this;
    }
    Int operator - (int a) {
        int p = x - a;
        if (p < 0)
            p += mod;
        return p;
    }
};

Int deg(Int a, int d) {
    Int ans(1);
    while (d) {
        if (d % 2) {
            ans *= a;
        }
        a *= a;
        d /= 2;
    }
    return ans;
}


signed main() {
#ifdef MY
    freopen("f.in", "r", stdin);
    //freopen("f.out", "w", stdout);
#endif // MY
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    Int k = deg(2, m) - 1;
    Int p = deg(k, n);
    cout << p.x;
    return 0;
}
