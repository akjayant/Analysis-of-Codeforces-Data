#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int inf = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
    }
    vector<int> cases;
    int pos = 0;
    while (pos < s.size()) {
        if (s[pos] == 'n') {
            int cnt = 0;
            while (pos < s.size() && s[pos] == 'n') {
                ++pos;
                ++cnt;
            }
            if (cnt >= 2) cases.push_back(cnt);
        } else if (s[pos] == 'u') {
            int cnt = 0;
            while (pos < s.size() && s[pos] == 'u') {
                ++pos;
                ++cnt;
            }
            if (cnt >= 2) cases.push_back(cnt);
        } else {
            ++pos;
        }
    }
    long long answer = 1;
    long long dp[MAXN];
    for (int i = 0; i < MAXN; ++i) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < MAXN - 2; ++i) {
        dp[i + 1] = (dp[i] + dp[i + 1]) % inf;
        dp[i + 2] = (dp[i] + dp[i + 2]) % inf;
    }
    for (int i = 0; i < cases.size(); ++i) {
        answer = (answer * (long long)dp[cases[i]]) % inf;
    }
    cout << answer;
    return 0;
}