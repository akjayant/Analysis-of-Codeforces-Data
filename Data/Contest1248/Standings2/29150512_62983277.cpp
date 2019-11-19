#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e5 + 5;

long long v[Dim];
long long n, mn, mx, ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> v[i];
    }

    sort (v + 1, v + n + 1);
    for (int i = 1; i <= n / 2; ++ i) {
        mn += v[i];
    }

    for (int i = n / 2 + 1; i <= n; ++ i) {
        mx += v[i];
    }

    ans = mn * mn + mx * mx;
    cout << ans << '\n';

    return 0;
}
