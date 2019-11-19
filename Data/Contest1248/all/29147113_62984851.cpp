#include <bits/stdc++.h>

using namespace std;

int a[111111];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x = 0, y = 0;
    for (int i = n / 2; i < n; i++) {
        x += a[i];
    }
    for (int i = 0; i < n/ 2; i++) {
        y += a[i];
    }
    cout << x * x + y * y << endl;
}
