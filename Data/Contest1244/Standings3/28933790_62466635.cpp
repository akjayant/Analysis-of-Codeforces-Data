#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        bool found = false;
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100; y++) {
                if (found) continue;
                if ((c * x >= a) && (d * y >= b) && ((x + y) <= k)) {
                    cout << x << " " << y << "\n";
                    found = true;
                }
            }
        }
        if (!found) cout << "-1\n";
    }
}
