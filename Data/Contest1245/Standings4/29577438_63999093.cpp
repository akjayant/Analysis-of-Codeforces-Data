#include<bits/stdc++.h>


using namespace std;

const int N = 1e6 + 2, MOD = 998244353;

#define ss second
#define ff first
#define int long long

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int aa[N];

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, kol = 0;
        cin >> n >> a >> b >> c;
        string s = "";
        for (int i = 0; i < n; i++) s+= ".";
        for (int i = 0; i < n; i++) {
            char cc;
            cin >> cc;
            if (cc == 'R') {
                if (b > 0) {
                    kol++;
                    b--;
                    s[i] = 'P';
                }
            }
            if (cc == 'P') {
                if (c > 0) {
                    c--;
                    kol++;
                    s[i] = 'S';
                }
            }
            if (cc == 'S') {
                if (a > 0) {
                    a--;
                    kol++;
                    s[i] = 'R';
                }
            }
        }
        if (kol >= (n + 1) / 2) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (s[i] == '.') {
                   if (a > 0) {
                        a--;
                        cout << 'R';
                        continue;
                   }
                   if (b > 0) {
                        b--;
                        cout << 'P';
                        continue;
                   }
                   cout << 'S';
                   c--;
                }
                else cout << s[i];
            }
            cout << "\n";
        }
        else cout << "NO\n";
    }
}
