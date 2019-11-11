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
    int a, b, c, n;
    string s;
    cin >> n >> a >> b >> c;
    cin >> s;
    unordered_map <char, int> um;
    for (char si : s)
        um[si]++;

    int sum = min(b, um['R']) + min(a, um['S']) + min(c, um['P']);
    if (sum < (n + 1) / 2) {
        cout << "NO\n";
        return;
    }
    int d = min(b, um['R']);
    int e = min(a, um['S']);
    int f = min(c, um['P']);
    cout << "YES\n";
    for (char si : s) {
        if (si == 'R') {
            if (d) {
                --d;
                --b;
                cout << 'P';
            }
            else {
                if (a > e) {
                    cout << 'R';
                    --a;
                }
                else {
                    cout << "S";
                    --c;
                }
            }
        }
        else if (si == 'S') {
            if (e) {
                --e;
                --a;
                cout << "R";
            }
            else {
                if (b > d) {
                    cout << 'P';
                    --b;
                }
                else {
                    cout << "S";
                    --c;
                }
            }
        }
        else {
            if (f) {
                --f;
                --c;
                cout << "S";
            }
            else {
                if (b > d) {
                    cout << "P";
                    --b;
                }
                else {
                    cout << "R";
                    --a;
                }
            }
        }
    }
    cout << '\n';
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