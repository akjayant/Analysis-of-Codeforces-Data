#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    ll x = 0, y = 0;
    for (int i = 0; i < n / 2; i++) x += a[i];
    for (int i = n / 2; i < n; i++) y += a[i];
    cout << x * x + y * y << "\n";
    return 0;
}