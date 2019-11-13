#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; ++t) {
        int a, b, c; cin >> a >> b >> c;
        int maxgot = 0;
        for(int i = 0; i <= a; ++i) {
            int thisgot = 0;
            int acpy = a;
            int bcpy = b;
            int ccpy = c;
            int taken = min(a, min(b / 2, i));
            acpy -= taken;
            bcpy -= 2 * taken;
            thisgot += 3 * taken;
            taken = min(bcpy, ccpy / 2);
            thisgot += 3 * taken;
            maxgot = max(maxgot, thisgot);
        }
        cout << maxgot << endl;
    }
}
