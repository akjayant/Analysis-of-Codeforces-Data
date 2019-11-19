#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define ll long long
#define f first
#define s second
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int q = 0; q < t; q++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mi = 1e9, ma = -1, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                mi = min(i, mi);
                ma = max(i, ma);
                cnt++;
            }
        }
        if(ma == -1) {
            cout << n << "\n";
            continue;
        }
        cout << max(n + cnt, 2 * max(ma + 1, n - mi)) << "\n";
    }
    return 0;
}