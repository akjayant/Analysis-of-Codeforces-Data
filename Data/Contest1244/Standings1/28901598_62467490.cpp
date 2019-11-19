#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int inf = 1e9;

int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}

int test, n;

string s;

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> test;
    while(test--) {
        cin >> n;
        cin >> s;
        s = "+" + s;
        int mx = n;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1') {
                mx = max(mx, i + n - i + 1);
                mx = max(mx, 2 * i);
                mx = max(mx, 2 * (n - i + 1));
                mx = max(mx, i + n - i + 1);
            }
        }
        cout << mx << "\n";
    }
}
