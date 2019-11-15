#include <bits/stdc++.h>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        vector<char>place(n, '$');
        for(int i = 0; i < s.size(); i++) {
            if(place[i] != '$') continue;
            if(s[i] == 'S' && a > 0) {
                place[i] = 'R';
                a--;
            }
        }
        for(int i = 0; i < s.size(); i++) {
            if(place[i] != '$') continue;
            if(s[i] == 'R' && b > 0) {
                place[i] = 'P';  b--;
            }
        }
        for(int i = 0; i < s.size(); i++) {
            if(place[i] != '$') continue;
            if(s[i] == 'P' && c > 0) {
                place[i] = 'S'; c--;
            }
        }
        int win = 0;
        for(int i = 0; i < s.size(); i++)
            if(place[i] != '$')
                win++;

        if(win < (n + 1) / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i = 0; i < s.size(); i++) {
                if(place[i] == '$') {
                    if(a > 0) place[i] = 'R', a--;
                    else if(b > 0) place[i] = 'P', b--;
                    else place[i] = 'S', c--;
                }
                cout<<place[i];
            }
            cout << '\n';
        }
    }
}
