#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mp make_pair
#define sqr(s) ((s) * (s))
 
using namespace std;
 
typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;


int fpow(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    cout << fpow(fpow(2, m) + MOD - 1, n) << endl;
}
