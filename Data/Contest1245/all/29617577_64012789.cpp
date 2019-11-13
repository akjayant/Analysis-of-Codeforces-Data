#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

int gcd(int a, int b) {
    while (b) {
        int p = a;
        a = b;
        b = p % b;
    }
    return a;
}


signed main() {
    fastio
    int q;
    cin >> q;
    while (q--) {
        int n;
        int a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        int cnt = 0;
        string s1 = s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R' && b) {
                --b;
                ++cnt;
                s1[i] = 'P';
                continue;
            }
            if (s[i] == 'P' && c) {
                --c;
                ++cnt;
                s1[i] = 'S';
                continue;
            }
            if (s[i] == 'S' && a) {
                --a;
                ++cnt;
                s1[i] = 'R';
                continue;
            }
            s1[i] = '.';
        }
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.') {
                if (a) {
                    --a;
                    s1[i] = 'R';
                } else if (b) {
                    --b;
                    s1[i] = 'P';
                } else {
                    --c;
                    s1[i] = 'S';
                }
            }
        }
        cnt >= (n + 1) / 2 ? cout << "YES\n" << s1 << '\n' : cout << "NO\n";
    }
}