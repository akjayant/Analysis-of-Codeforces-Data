#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++i)

int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    string str; cin >> str;
    int n = str.size();
    vector<int> d(n + 7);
    d[0] = 1;
    F(i, n + 3) {
        d[i + 1] = (d[i] + d[i + 1]) % MOD;
        d[i + 2] = (d[i] + d[i + 2]) % MOD;
    }
    int cnt = 0;
    char cur = '!';
    int ans = 1;
    F(i, n) {
        if(str[i] == 'm' || str[i] == 'w') {
            ans = 0;
        }
        if (str[i] == cur) {
            ++ cnt;
        } else {
            if(cur == 'u' || cur == 'n') {
                ans = ans * d[cnt] % MOD;
            }
            cnt = 1;
            cur = str[i];
        }
    }
    if(cur == 'u' || cur == 'n') {
                ans = ans * d[cnt] % MOD;
            }
    cout << ans;
}
