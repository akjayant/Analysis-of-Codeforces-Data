#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> hoge(n);
    for (int i = 0; i < n; i++) {
        hoge[i] = i;
    }

    vector<int> v(n * n);
    for (int i = 1; i <= n * n; i++) v[i-1] = i;
    for (int i = n; i < n * n; i += 2 * n) {
        reverse(v.begin() + i, v.begin() + i + n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i + j * n] << " \n"[j + 1 == n];
        }
    }
    return 0;
}