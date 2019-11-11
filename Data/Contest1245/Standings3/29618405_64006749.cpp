#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int ca = 0, cb = 0, cc = 0;
        string s; cin >> s;
        for(int i=0; i<n; ++i) {
            if(s[i] == 'R') ++cb;
            else if(s[i] == 'P') ++cc;
            else ++ca;
        }
        
        int win = min(a, ca) + min(b, cb) + min(c, cc);
        if(win >= (n + 1) / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            continue;
        }

        string res = string(n, '#');
        for(int i=0; i<n; ++i) {
            if(s[i] == 'R') {
                if(b == 0) continue;
                res[i] = 'P'; --b;
            } else if(s[i] == 'P'){
                if(c == 0) continue;
                res[i] = 'S'; --c;
            } else {
                if(a == 0) continue;
                res[i] = 'R'; --a;
            }
        }

        for(int i=0; i<n; ++i) {
            if(res[i] != '#') continue;
            if(b > 0) {
                res[i] = 'P'; --b;
            } else if(c > 0){
                res[i] = 'S'; --c;
            } else {
                res[i] = 'R'; --a;
            }
        }

        cout << res << '\n';
    }
}