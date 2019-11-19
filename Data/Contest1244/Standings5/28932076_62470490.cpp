#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fi first
#define sec second
#define pb push_back
#define pi pair <int, int>
#define len length()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = s.len, r = -1;
    loop(i, s.len)
        if (s[i] == '1') {
            if (l == s.len)
                l = i;
            r = i;
        }
    cout << max({(int)s.len, (s.len - l) * 2, (r + 1) * 2}) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    loop(i, t)
    solve();
    return 0;
}
