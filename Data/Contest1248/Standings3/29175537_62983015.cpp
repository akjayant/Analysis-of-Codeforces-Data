#include <bits/stdc++.h>

using namespace std;

//#define Local

const int maxn = 1e5 + 9;

int a[maxn];

int main(void) {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("test/input.in", "r", stdin);
    //freopen("../output.out", "w", stdout);
#endif // Local
    int n; cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    int mid = n / 2;
    if (n & 1)
        mid = (n - 1) / 2;
    long long sum1 = 0;
    for (int i = 0; i < mid; i ++) {
        sum1 += a[i];
    }
    long long sum2 = sum - sum1;
    long long ans = sum1 * sum1 + sum2 * sum2;
    cout << ans << endl;
    return 0;
}
