#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        cin >> s;
        int firste = -1, laste = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                laste = i;
            if (s[i] == '1' && firste == -1)
                firste = i;
        }
        if (firste == -1) {
            cout << n << "\n";
            continue;
        }
        int d1 = laste + 1, d2 = n - firste;
        cout << max(d1, d2) * 2 << "\n";
    }
}
