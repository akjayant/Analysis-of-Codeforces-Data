#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int a[505][505];
int main() {
    int n;
    cin >> n;
    int k = 0;
    for (int j = 1; j <= n; j++) {
        if (j % 2)
            for (int i = 1; i <= n; i++) {
                a[i][j] = ++k;
            }
        else
            for (int i = n; i >= 1; i--) {
                a[i][j] = ++k;
            }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) printf("%d%c", a[i][j], " \n"[j == n]);
    return 0;
}
