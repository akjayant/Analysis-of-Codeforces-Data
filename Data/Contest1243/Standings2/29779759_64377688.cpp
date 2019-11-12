#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int inf = 1e9 + 7;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int y = 0; y < t; ++y) {
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        vector<int> nots;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) nots.push_back(i);
        }
        if (nots.size() == 0) {
            cout << "Yes" << endl;
            continue;
        }
        if (nots.size() == 2) {
            char c1 = s[nots[0]];
            char c2 = s[nots[1]];
            char c3 = t[nots[0]];
            char c4 = t[nots[1]];
            if (c1 == c2 && c3 == c4) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}