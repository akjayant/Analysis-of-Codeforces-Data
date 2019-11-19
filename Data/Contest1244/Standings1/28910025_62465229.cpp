#include <bits/stdc++.h>
#define N ((int)1e6+10)
#define MD ((int)1e9+7)

using namespace std;
int a, b, c, d, q, k;

int main() {
    cin >> q;
    while (q--) {
        cin >> a >> b >> c >> d >> k;
        int x = a / c + (a % c != 0);
        int y = b / d + (b % d != 0);
        if (x + y > k)
            cout << -1 << endl;
        else
            cout << x << " " << y << endl;
    }

    return 0;
}
