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
//#define int long long
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

const int N = 305;
int ans[N][N];
int ind[N];

signed main() {
#ifdef MY
    freopen("f.in", "r", stdin);
    //freopen("f.out", "w", stdout);
#endif // MY
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j * 2 < n; j++) {
            int t = n - j - 1;
            //int k = min(i, n - i - 1);
            int a = i * n + j, b = i * n + t;
            if (i % 2) {
                swap(a, b);
            }
            ans[j][ind[j]++] = a;
            if (t != j)
                ans[t][ind[t]++] = b;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}
