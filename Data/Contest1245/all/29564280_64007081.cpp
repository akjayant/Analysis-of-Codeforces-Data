#include <bits/stdc++.h>

using namespace std;

const long long SZ = 26, MAXN = 1e5 + 20, MAXM = 1410, mod = 1e9 + 7, inf = 1e9 + 100, L = 19;
const double eps = 1e-9, Pi = acos(-1);
mt19937 rnd;

long long d[MAXN];

void solve () {
    string s;
    cin >> s;
    d[0] = 1;
    char last = '#';
    for (int j = 0; j < s.length(); ++j) {
        if (s[j] == 'm' || s[j] == 'w') {
            cout << "0\n";
            return;
        }
        d[j + 1] = d[j];
        if ((s[j] == 'n' && last == 'n') || (s[j] == 'u' && last == 'u')){
            d[j + 1] += d[j - 1];
        }
        d[j + 1] %= mod;
        last = s[j];
    }
    cout << d[s.length()] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);

    int t = 1;
    while (t--)
        solve();
}