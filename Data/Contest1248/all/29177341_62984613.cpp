#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long small_sum = 0, large_sum = 0;
    for (int i = 0; i < n / 2; i++) {
        small_sum += a[i];
    }
    for (int i = n /2; i < n; i++) {
        large_sum += a[i];
    }
    cout << (small_sum * small_sum + large_sum * large_sum) << '\n';
    return 0;
}
