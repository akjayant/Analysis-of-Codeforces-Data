#include<bits/stdc++.h>

void solve() {
    int a, b, c, ans = 0;
    scanf("%d%d%d", &a, &b, &c);
    int d = std::min(b, c / 2);
    ans += 3 * d;
    b -= d;
    d = std::min(a, b / 2);
    ans += 3 * d;
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
