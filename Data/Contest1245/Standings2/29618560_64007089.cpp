#include <bits/stdc++.h>
using namespace std;

const int dim = 100010;
const int mod = 1000000007;

void solve() {
    string s; cin >> s;
    vector<int> batches;
    int curr = 0;
    if (s[0] == 'm' || s[0] == 'w') {
        cout << "0\n";
        return;
    }
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << "0\n";
            return;
        }
        if (curr == 0 && s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n'))
            curr = 2;
        else if (s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n'))
            curr++;
        else if (s[i] != s[i-1] && curr) {
            batches.push_back(curr);
            curr = 0;
        }
    }
    if (curr)
        batches.push_back(curr);
    int sol = 1;
    vector<int> f(dim);
    f[2] = 2, f[3] = 3;
    for (int i = 4; i <= (int)s.size(); ++i)
        f[i] = (f[i-1] + f[i-2]) % mod;
    for (auto it : batches) {
        sol = (1LL * sol * f[it]) % mod;
    }
    cout << sol << endl;
}

int main() {
    #ifdef LOCAL
        freopen("date.in", "r", stdin);
    #endif
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}