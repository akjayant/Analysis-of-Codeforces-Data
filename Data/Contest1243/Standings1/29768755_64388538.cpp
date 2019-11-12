#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define int long long
#define ll long long
#define ins insert
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define ld long double
#define rsz resize
#define pii pair<int, int>

using namespace std;

mt19937 rnd(time(nullptr));

const long long INF = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pii> ans;
        bool fl = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == t[j]) {
                    //cout << s << ' ' << t << "\n";
                    swap(s[i + 1], t[j]);
                    swap(t[i], s[i + 1]);
                    ans.pb({i + 2, j + 1});
                    ans.pb({i + 2, i + 1});
                    fl = 1;
                    break;
                }
                if (t[i] == t[j]) {
                   // cout << s << ' ' << t << "\n";
                    swap(s[i], t[j]);
                    ans.pb({i + 1, j + 1});
                    fl = 1;
                    break;
                }
                if (s[i] == s[j]) {
                    //cout << s << ' ' << t << "\n";
                    swap(s[j], t[i]);
                    ans.pb({j + 1, i + 1});
                    break;
                }
                if (t[i] == s[j]) {
                    //cout << s << ' ' << t << "\n";
                    swap(t[i + 1], s[j]);
                    swap(s[i], t[i + 1]);
                    ans.pb({j + 1, i + 2});
                    ans.pb({i + 1, i + 2});
                    fl = 1;
                    break;
                }
            }
        }
        if (s != t) {
            //cout << s << ' ' << t << "\n";
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (pii elem : ans) {
            cout << elem.ff << ' ' << elem.ss << "\n";
        }
    }
    return 0;
}
