#include <bits/stdc++.h>

#define MAXN 305

using namespace std;

int n, m;
vector<int> a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= n; ++j)
            a[j].push_back(++m);
        for (int j = n; j >= 1; --j)
            a[j].push_back(++m);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", a[i][j]);
        puts("");
    }
}
