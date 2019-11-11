#include <bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll INF = 1e17;
const ll MN = 1000000;


int main() {
    fast
    int t;
    cin >> t;
    map<char, char> win;
    win['R'] = 'S';
    win['P'] = 'R';
    win['S'] = 'P';
    map<char, int> mp;
    map<char, int> m;
    string s;
    while (t--) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        mp['R'] = a;
        mp['P'] = b;
        mp['S'] = c;
        cin >> s;
        m['R'] = 0;
        m['P'] = 0;
        m['S'] = 0;
        vector<pair<int, int>> p;
        for (auto i : mp) {
            p.emplace_back(i.second, i.first);
        }
        sort(all(p));
        reverse(all(p));
        vector<char> ans(n);
        int d = 0;
        for (auto[cnt, r] : p) {
            for (int i = 0; i < n; i++) {
                if (s[i] == win[r]) {
                    if (cnt > 0) {
                        ans[i] = r;
                        cnt--;
                        mp[r]--;
                        d++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                for (auto j : mp) {
                    if (j.second) {
                        ans[i] = j.first;
                        mp[j.first]--;
                        break;
                    }
                }
            }
        }
        if (d >= (n + 1) / 2) {
            cout << "YES\n";
            for (auto i : ans)
                cout << i;
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}