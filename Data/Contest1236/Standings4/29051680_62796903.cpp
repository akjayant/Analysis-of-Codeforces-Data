#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 305;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int a[maxn][maxn];

int main() {

    int n; scanf("%d", &n);

    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] = ++tot;
        }
        i++;
        for (int j = n - 1; j >= 0; j--) {
            a[j][i] = ++tot;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", a[i][0]);
        for (int j = 1; j < n; j++) {
            printf(" %d", a[i][j]);
        }
        putchar('\n');
    }

    return 0;
}