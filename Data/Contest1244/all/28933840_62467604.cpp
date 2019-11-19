#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;

int main() {
    cout.precision(20);
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int pos1 = -1;
        int pos2 = n;
        for (int i = 0; i < n; ++i) if (s[i] == '1') pos1 = i;
        for (int i = n - 1; i >= 0; --i) if (s[i] == '1') pos2 = i;
        if (pos1 == -1) {
            cout << n << endl;
        } else {
            cout << max(max(n - pos1, pos1 + 1), max(n - pos2, pos2 + 1)) * 2 << endl;
        }
    }
    return 0;
}