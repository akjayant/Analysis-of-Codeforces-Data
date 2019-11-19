#include <iostream>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    int n, m, x;
    ll c1, c2;
    while (t--) {
        cin >> n;
        c1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x & 1) c1++;
        }
        cin >> m;
        c2 = 0;
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (x & 1) c2++;
        }
        cout << c1 * c2 + (c1 - n) * (c2 - m) << "\n";
    }
    return 0;
}