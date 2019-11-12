#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int cnt = 0;
        while (b > 0 && c > 1) {
            cnt += 3;
            --b;
            --c; --c;
        }
        while (a > 0 && b > 1) {
            cnt += 3;
            --a;
            --b; --b;
        }

        cout << cnt << '\n';
    }

    return 0;
}