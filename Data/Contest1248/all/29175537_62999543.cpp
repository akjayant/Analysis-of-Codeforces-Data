#include <bits/stdc++.h>

using namespace std;

//#define Local

const int mod = 1e9 + 7;

long long ans[100010];

int main(void) {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("test/input.in", "r", stdin);
    //freopen("../output.out", "w", stdout);
#endif // Local
    int n, m; cin >> n >> m;
    ans[0] = 2, ans[1] = 2;
    long long sum = 0;
    for (int i = 2; i <= 100000; i ++) {
        ans[i] = (ans[i - 1] + ans[i - 2]) % mod;
    }
    sum = (ans[n] + ans[m]) % mod;
    sum = (sum - ans[1] + mod) % mod;
    cout << sum << endl;
    return 0;
}
