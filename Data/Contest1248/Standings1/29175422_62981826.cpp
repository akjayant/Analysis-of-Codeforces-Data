#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll x = 0, y = 0;
    for (int i = 0; i < n / 2; ++i) {
        x += a[i];
    }
    for (int i = n / 2; i < n; ++i) {
        y += a[i];
    }

    cout << x * x + y * y << endl;
}
