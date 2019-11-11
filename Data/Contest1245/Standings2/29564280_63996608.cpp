#include <bits/stdc++.h>

using namespace std;

const long long SZ = 26, MAXN = 2e5 + 20, MAXM = 1410, mod = 1e8, inf = 1e9 + 100, L = 19;
const double eps = 1e-9, Pi = acos(-1);
mt19937 rnd;

int q[MAXN];

int gcd (int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    return a + b;
}
void solve () {
    int a, b;
    cin >> a >> b;
    if (gcd(a, b) > 1)
        cout << "Infinite\n";
    else
        cout << "Finite\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}