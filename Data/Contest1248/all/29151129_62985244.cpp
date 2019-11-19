#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

typedef long long ll;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const ll INF64 = 1e18;
const double INFD = 1e30;
const double EPS = 1e-6;
const double PI = 3.14159265;
const ll MOD = 1e8;

template <typename T>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}

const int MAXN = 100005;
int n, m, k;
int CASE;
int arr1[MAXN];
multiset<int> ss;
int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        arr1[i] = read<int>();
    }
    sort(arr1, arr1 + n);
    int xx = 0, yy = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i > n / 2 - 1) {
            xx += arr1[i];
        } else {
            yy += arr1[i];
        }
    }
    printf("%lld", (ll)xx * (ll)xx + (ll)yy * (ll)yy);

    return 0;
}