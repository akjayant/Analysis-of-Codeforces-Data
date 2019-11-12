#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                cout << (n * j + i) << ' ';
            } else {
                cout << (n * j + n + 1 - i) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
