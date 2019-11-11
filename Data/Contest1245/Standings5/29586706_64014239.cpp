#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

string s;
ll dp[maxn];
int l, last;
ll r = 1;

int main() {
    dp[0] = dp[1] = 1;
    inc(i, 2, 100000) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cin >> s;
    l = s.size();
    for (int i = 0; i < l;) {
        if (s[i] == 'w' || s[i] == 'm') {
            puts("0");
            return 0;
        }
        if (s[i] != 'u' && s[i] != 'n') {
            i++;
            continue;
        }
        for (last = i; last < l; last++)
            if (s[last] != s[i]) break;
        r = r * dp[last - i] % mod;
        i = last;
    }
    cout << r;
}