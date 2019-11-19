#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, a[N], sum, ans, col, row;

int main() {
    cin >> n;
    rep(i, 1, n) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    // ans = sum * sum;
    sort(a + 1, a + n + 1);
    int tmp = n / 2;
    rep(i, 1, tmp) {
        col += a[i];
    }
    row = sum - col;
    ans = row * row + col * col;
    printf("%lld\n", ans);
    return 0;
}
