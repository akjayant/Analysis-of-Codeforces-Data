


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 1000000 + 5;

long long n, lim;
long long num[MaxN];

int main() {
    cin >> n >> lim;
    memset(num, 0, sizeof num);
    long long ans = 0;
    for (int k = 0; k < n; ++ k) {
        num[k] = k + 1;
        ans += num[k];
    }
    if (ans <= lim) {
        for (int k = 0; k + k < n && ans < lim; ++ k) {
            long long det = min(lim - ans, num[n - k - 1] - num[k]);
            swap(num[k], num[k + det]);
            ans += det;
        }
        cout << ans << endl;
        for (int k = 0; k < n - 1; ++ k)
            printf("%d ", k + 1);
        printf("%d\n", n);
        for (int k = 0; k < n - 1; ++ k)
            printf("%d ", num[k]);
        printf("%d\n", num[n - 1]);
    }
    else puts("-1");
    
    return 0;
}
