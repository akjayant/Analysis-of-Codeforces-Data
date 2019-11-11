#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> f(100005);
    f[0] = 1;
    f[1] = 1;
    const long long MOD = 1e9 + 7;
    for (int i = 2; i < 100001; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    char last = 'A';
    int len = 0;
    long long ans = 1;
    for (int i = 0; i < (int)s.length(); ++i) {
        if(s[i] == last) {
            if (s[i] == 'u' || s[i] == 'n') {
                ++len;
            }
            last = s[i];
        } else {
            ans = ans * f[len] % MOD;
            len = 0;
            last = s[i];
            if (s[i] == 'u' || s[i] == 'n') len = 1;
        }
    }
    if (last == 'u' || last == 'n') ans = ans * f[len] % MOD;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            ans = 0;
        }
    }
    cout << ans << endl;
    return 0;
}

