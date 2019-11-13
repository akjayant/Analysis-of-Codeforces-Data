#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;

int t, n;

int main() {
    cin >> n;
    inc(i, 1, n) {
        inc(j, 1, n) {
            if (j & 1)
                printf("%d ", (j - 1) * n + i);
            else
                printf("%d ", j * n - i + 1);
        }
        printf("\n");
    }
}