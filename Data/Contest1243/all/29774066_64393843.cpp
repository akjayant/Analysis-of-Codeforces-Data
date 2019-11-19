#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;
typedef unsigned short ush;
typedef short shrt;
using namespace std;

#define int long long

const static int MAX_N = 5e5 + 7, INF = 1e9 + 7;
const static ld PI = acos(-1), eps = 1e-9;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int nokk(int a, int b) {
    return a / gcd(a, b) * b;
}

inline void prc();
signed main() {
    prc();
    int n; cin >> n;
    set<int> divs;
    for (int i = 2LL; i * i <= n; i++) {
        if (n % i == 0LL) {
            divs.insert(i);
            divs.insert(n / i);
        }
    }
    int nok = 1;
    for (int x : divs) {
        nok = nokk(x, nok);
    }
    cout << n / nok;
    return 0;
}

inline void prc() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}