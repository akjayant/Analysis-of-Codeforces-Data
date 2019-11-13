#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

int cnt[26];

void solve() {
    for(int i = 0; i < 26; i++) cnt[i] = 0;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++) cnt[s[i]-'a']++;
    for(int i = 0; i < n; i++) cnt[t[i]-'a']++;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] % 2 == 1) {
            cout << "No\n";
            return;
        }
    }

    vector <pii> ans;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            int idx = -1;
            for(int j = i + 1; j < n; j++) {
                if(s[j] == s[i]) {
                    idx = j;
                    break;
                }
            }
            if(idx != -1) {
                ans.eb(idx, i);
                swap(s[idx], t[i]);
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                if(t[j] == s[i]) {
                    idx = j;
                    break;
                }
            }
            ans.eb(idx, idx);
            swap(s[idx], t[idx]);
            ans.eb(idx, i);
            swap(s[idx], t[i]);
        }
    }
    cout << "Yes\n";
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i.fi+1 << ' ' << i.se+1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}