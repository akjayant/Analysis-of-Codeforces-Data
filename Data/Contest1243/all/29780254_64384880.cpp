#include <bits/stdc++.h>
using namespace std;

bool same(char c, vector<char> a) {
    for (char _c : a) {
        if (c == _c) return true;
    }
    return false;
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int first = -1;
    int second = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else {
                cout << "No\n";
                return;
            }
        }
    }

    if (first == -1 || second == -1) {
        cout << "No\n";
        return;
    }

    if (s[first] == s[second] && t[first] == t[second]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int qt;
    cin >> qt;
    for (int q = 0; q < qt; q++) solve();
}
