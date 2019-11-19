#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;
        long long a = 0, b = 0, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            int q;
            cin >> q;
            if (q % 2 == 0) {
                a++;
            } else {
                b++;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int q;
            cin >> q;
            if (q % 2 == 0) {
                x++;
            } else {
                y++;
            }
        }
        cout << a * x + b * y << endl;
    }
}
