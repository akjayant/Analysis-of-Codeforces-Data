#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, q;
        long long even_p = 0, even_q = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p;
            if (p % 2 == 0) {
                even_p++;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> q;
            if (q % 2 == 0) {
                even_q++;
            }
        }
        cout << (even_p * even_q + (n - even_p) * (m - even_q)) << '\n';
    }
    return 0;
}
