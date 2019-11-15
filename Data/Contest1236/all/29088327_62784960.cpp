#include <bits/stdc++.h>

using namespace std;


void solve() {
    int x,y,z;
    cin >> x >> y >> z;
    int res = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i*2+j <= y && 2*j <= z) {
                res = max(res, i+j);
            }
        }
    }
    res *= 3;
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)solve();
    cout << endl;
}
