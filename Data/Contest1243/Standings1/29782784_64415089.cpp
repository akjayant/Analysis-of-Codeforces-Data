#include <bits/stdc++.h>
#define fi first
#define se second
using ll = long long;
using namespace std;

vector<pair<int, int>> mv;
int n;

void move(string& s, string& t, int r) {
    if(s[r] == t[r]) return;
    for(int i = r + 1; i < n; ++i) {
        if(s[i] == s[r]) {
            mv.push_back({i, r});
            swap(s[i], t[r]);
            return;
        }
        if(t[i] == t[r]) {
            mv.push_back({r, i});
            swap(s[r], t[i]);
            return;
        }
    }
    mv.push_back({r, r});
    swap(s[r], t[r]);
    move(s, t, r);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        mv.clear();
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> cnts(26, 0), cntt(26, 0);
        for(char c : s) cnts[c - 'a'] += 1;
        for(char c : t) cntt[c - 'a'] += 1;
        bool ok = true;
        for(int i = 0; i < 26; ++i) ok &= (cnts[i] + cntt[i]) % 2 == 0;
        if(!ok) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for(int i = 0; i < n - 1; ++i) {
                move(s, t, i);
            }
            assert(mv.size() <= 2 * n);
            cout << mv.size() << '\n';
            for(auto e : mv) cout << e.fi + 1 << ' ' << e.se + 1 << '\n';
        }
    }
}
