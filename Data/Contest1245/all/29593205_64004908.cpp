#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char ans[105];
int main() {
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        map<char, int> mp;
        map<char, vector<int>> loc;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            loc[s[i]].push_back(i);
        }
        int pakea = min(a, mp['S']);
        int pakeb = min(b, mp['R']);
        int pakec = min(c, mp['P']);
        a -= pakea;
        b -= pakeb;
        c -= pakec;
        int win = pakea + pakeb + pakec;
        int lb = n % 2 == 0? n / 2 : n / 2 + 1;
        if (win >= lb) {
            for (int i = 0; i < n; i++) {
                ans[i] = '-';
            }
            for(int idx: loc['S']) {
                if (pakea <= 0) break;
                ans[idx] = 'R';
                pakea--;
            }
            for(int idx: loc['R']) {
                if (pakeb <= 0) break;
                ans[idx] = 'P';
                pakeb--;
            }
            for(int idx: loc['P']) {
                if (pakec <= 0) break;
                ans[idx] = 'S';
                pakec--;
            }
            for (int i = 0; i < n; i++) {
                if (ans[i] == '-') {
                    if (a > 0) {
                        ans[i] = 'R';
                        a--;
                        continue;
                    }
                    if (b > 0) {
                        ans[i] = 'P';
                        b--;
                        continue;
                    }
                    if (c > 0) {
                        ans[i] = 'S';
                        c--;
                        continue;
                    }
                }
            }
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << ans[i];
            }
            cout << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}