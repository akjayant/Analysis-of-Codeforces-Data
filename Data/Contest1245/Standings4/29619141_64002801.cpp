#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define x first
#define y second
#define pb push_back
#define len(x) (int) x.size();
#define all(a) a.begin(), a.end()

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a) for (int i = 0; i < a.size(); ++i) cin >> a[i];
#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;
#define printvp(x, text) cout << text << " =\n"; for (auto e : x) cout << e.first << ' ' << e.second << endl; cout << endl;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    fast_io;

    int t;
    cin >> t;
    for (int y = 0; y < t; ++y) {
        int n, a, b, c;
        string s;
        cin >> n >> a >> b >> c >> s;

        int cnt = 0;
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R') {
                if (b > 0) {cnt++, b--;
                ans.pb('P');}
                else ans.pb('.');
            }
            else if (s[i] == 'P') {
                if (c > 0) {cnt++, c--;
                ans.pb('S');}
                else ans.pb('.');
            }
            else if (s[i] == 'S') {
                if (a > 0) {cnt++, a--;
                ans.pb('R');}
                else ans.pb('.');
            }
        }

        for (int i = 0; i < n; ++i) {
            if (ans[i] == '.') {
                if (a > 0) {ans[i] = 'R'; a--;}
                else if (b > 0) {ans[i] = 'P'; b--;}
                else if (c > 0) {ans[i] = 'S'; c--;}
            }
        }

        if (cnt >= (n + 1) / 2) cout << "YES\n" << ans << "\n";
        else cout << "NO\n";
    }
}
