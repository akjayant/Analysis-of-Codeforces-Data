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
int arr2[MAXN];
int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int o1 = 0;
        for (int i = 0; i < n; i++) {
            arr1[i] = read<int>();
            o1 += arr1[i] & 1;
        }
        scanf("%d", &m);
        int o2 = 0;
        for (int i = 0; i < m; i++) {
            arr2[i] = read<int>();
            o2 += arr2[i] & 1;
        }
        ll ans = (ll)o1 * (ll)o2 + (ll)(n - o1) * (ll)(m - o2);
        printf("%lld\n", ans);
    }
    return 0;
}