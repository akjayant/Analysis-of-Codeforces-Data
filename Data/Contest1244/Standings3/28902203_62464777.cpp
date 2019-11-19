#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if ((a + c - 1) / c + (b + d - 1) / d <= k)
            cout << (a + c - 1) / c << " " << (b + d - 1) / d << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}