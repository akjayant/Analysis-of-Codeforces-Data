#include <bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll INF = 1e17;
const ll MN = 1000000;
const ll mod = 1e9 + 7;

void add(int &a, int &b) {
    a += b;
    while (a >= mod)
        a -= mod;
}

int main() {
    fast
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0;
            return 0;
        }
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (s[i] == 'u' && s[i - 1] == 'u') {
                add(dp[i + 1], dp[i - 1]);
            }
            if (s[i] == 'n' && s[i - 1] == 'n')
                add(dp[i + 1], dp[i - 1]);
        }
        add(dp[i + 1], dp[i]);
    }
    cout << dp[n];
}