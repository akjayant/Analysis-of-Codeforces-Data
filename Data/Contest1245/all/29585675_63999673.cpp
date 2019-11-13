#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int f[5];
char upd[1005];
void solve () {
    int n; cin >> n;
    int r, p, c; cin >> r >> p >> c;
    f[1] = r, f[2] = p, f[3] = c;
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        upd[i] = 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R' && f[2] > 0) f[2]--, upd[i] = 'P', cnt++;
        else if (s[i] == 'P' && f[3] > 0) f[3]--, upd[i] = 'S', cnt++;
        else if (s[i] == 'S' && f[1] > 0) f[1]--, upd[i] = 'R', cnt++; 
    }
    if (cnt < n / 2 + (n % 2)) {
        cout << "No" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        if (upd[i]) cout << upd[i];
        else {
            if (f[1]) cout << 'R', f[1]--;
            else if (f[2]) cout << 'P', f[2]--;
            else cout << 'S', f[3]--;
        }
    }
    cout << endl;
}
 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}
 