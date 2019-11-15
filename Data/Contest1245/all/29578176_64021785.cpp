#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const lint MOD = 1e9 + 7;
const lint MAX = 1e5 + 7;

lint memo[MAX];

string s;

lint solve(int idx) {
    if (idx >= 0 && s[idx] == 'm' || s[idx] == 'w') return 0;
    if (idx <= 0) return 1;
    lint &ret = memo[idx];
    if (ret != -1) return ret;
    ret = 0LL;
    if (idx >= 1 && s[idx] == 'u' && s[idx - 1] == 'u') ret += solve(idx - 2) % MOD;
    if (idx >= 1 && s[idx] == 'n' && s[idx - 1] == 'n') ret += solve(idx - 2) % MOD;
    ret += solve(idx - 1) % MOD;
    ret %= MOD;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    memset(memo, -1LL, sizeof(memo));
    cout << solve(s.size() - 1) << '\n';
}
