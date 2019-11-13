#include <bits/stdc++.h>

using namespace std;

int n, a[20000], q;
string s, s1;

void solve() {
    cin >> n >> s >> s1;
    vector<int> v;
    int f = 0;
    int cnt[300];
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s1[i]) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) {
        cout << "Yes" << endl;
        return;
    }
    if (v.size() != 2) {
        cout << "No" << endl;
        return;
    }
    if (s[v[0]] == s[v[1]] && s1[v[0]] == s1[v[1]]) {
        cout << "Yes"<< endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin >> q;
    while (q != 0) {
        solve();
        q--;
    }
}

