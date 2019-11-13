#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rnd;
#define F first
#define S second
#define pb push_back


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        s = '*' + s;
        string t;
        for (int i=0; i<=n; i++) {
            t += "*";
        }
        for (int i=1; i<=n; i++) {
            if (s[i] == 'R' && b) {
                t[i] = 'P';
                b--;
            }
            if (s[i] == 'P' && c) {
                t[i] = 'S';
                c--;
            }
            if (s[i] == 'S' && a) {
                t[i] = 'R';
                a--;
            }
        }
        for (int i=1; i<=n; i++) {
            if (t[i] != '*') continue;
            if (a) {
                t[i] = 'R';
                a--;
            }
            else if (b) {
                t[i] = 'P';
                b--;
            }
            else {
                t[i] = 'S';
                c--;
            }
        }
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            if (s[i] == 'R' && t[i] == 'P') {
                cnt++;
            }
            if (s[i] == 'P' && t[i] == 'S') {
                cnt++;
            }
            if (s[i] == 'S' && t[i] == 'R') {
                cnt++;
            }
        }
        if (cnt >= (n+1)/2) {
            cout << "YES\n";
            for (int i=1; i<=n; i++) cout << t[i];
            cout << "\n";
        }
        else {
            cout << "NO\n";
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
