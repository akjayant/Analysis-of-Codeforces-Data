#include <bits/stdc++.h>

using namespace std;

int n, a[20000], q;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int i1 = 1; i1 <= i; i1++) {
            if (a[i1] < i) {
                cout << i - 1 << endl;
                return;
            }
        }
    }
    cout << n << endl;
}

int main() {
    cin >> q;
    while (q != 0) {
        solve();
        q--;
    }
}

