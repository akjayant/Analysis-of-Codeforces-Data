#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        int sol = 0;
        for (int i = 0; i <= x && y - 2 * i >= 0; i++) {
            int now = i + 2 * i;
            y -= 2 * i;
            int mx = min(y, z / 2);
            now += mx + mx * 2;
            y += 2 * i;
            sol = max(sol, now);
        }
        cout << sol << '\n';
    }
    return 0;
}
