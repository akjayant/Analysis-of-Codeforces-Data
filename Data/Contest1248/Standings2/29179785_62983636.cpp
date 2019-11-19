#include <map>
#include <set>
#include <cmath>
#include <ctime> 
#include <queue>
#include <stack>
#include <bitset> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define MP std::make_pair
#define PII std::pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CL(a, b) memset(a, b, sizeof a)
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, r, l) for (int i = (r); i >= (l); -- i)
#define PE(x, a) for (int x = head[a]; x;x = edge[x].next)

typedef long long ll;

const int MAXN = 1e5 + 6;

int n, a[MAXN];

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    std::sort(a + 1, a + n + 1);
    ll x = 0, y = 0;
    int l = 1, r = n;
    while (l < r) {
        x += a[l], y += a[r];
        l++; r--;
    }
    if (l == r) y += a[l];
    printf("%lld\n", x * x + y * y);
    return 0;
}