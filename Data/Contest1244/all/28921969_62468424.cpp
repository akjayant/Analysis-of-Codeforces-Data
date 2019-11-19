#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int m = a / c + (bool) (a % c);
        int n = b / d + (bool) (b % d);

        if (m + n > k)
            cout << "-1\n";
        else
            cout << m << ' ' << n << '\n';
    }
    return 0;
}
