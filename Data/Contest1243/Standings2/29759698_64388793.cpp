#include <bits/stdc++.h>

using namespace std;

int n, a[20000], q;
string s, s1;
int cnt[300], cnt1[300];

void solve() {
    vector<pair<int, int> > ans;
    cin >> n >> s >> s1;
    for (int i = 'a'; i <= 'z'; i++) {
        cnt[i] = 0;
        cnt1[i] = 0;
    }
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
        cnt1[s1[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if ((cnt[i] + cnt1[i]) % 2 == 1) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s1[i]) {
            for (int i1 = i + 1; i1 < s.size(); i1++) {
                if (s[i] == s[i1]) {
                    ans.push_back({i1, i});
                    swap(s[i1], s1[i]);
                    break;
                }
                if (s[i] == s1[i1]) {
                    ans.push_back({i1, i1});
                    swap(s[i1], s1[i1]);
                    ans.push_back({i1, i});
                    swap(s[i1], s1[i]);
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second  + 1<< endl;
    }
}

int main() {
    cin >> q;
    while (q != 0) {
        solve();
        q--;
    }
}

