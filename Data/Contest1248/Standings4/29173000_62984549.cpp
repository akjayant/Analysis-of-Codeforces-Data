#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> P;
#define VNAME(value) (#value)
#define bug printf("*********\n");
#define debug(x) cout<<"["<<VNAME(x)<<" = "<<x<<"]"<<endl;
#define mid ((l + r) >> 1)
#define chl 2 * k + 1
#define chr 2 * k + 2
#define lson l, mid, chl
#define rson mid + 1, r, chr
#define eb(x) emplace_back(x)
#define pb(x) emplace_back(x)
#define mem(a, b) memset(a, b, sizeof(a));

const LL mod = (LL) 1e9 + 7;
const int maxn = (int) 1e6 + 5;
const LL INF = 0x7fffffff;
const LL inf = 0x3f3f3f3f;
const double eps = 1e-8;

#ifndef ONLINE_JUDGE
clock_t prostart = clock();
#endif

void f() {
#ifndef ONLINE_JUDGE
    freopen("../data.in", "r", stdin);
#endif
}

//typedef __int128 LLL;

template<typename T>
void read(T &w) {//读入
    char c, k = 1;
    while (!isdigit(c = getchar()))c == '-' ? k = -1 : k = k;
    w = c & 15;
    while (isdigit(c = getchar()))
        w = w * 10 + (c & 15);
    w *= k;
}

template<typename T>
void output(T x) {
    if (x < 0)
        putchar('-'), x = -x;
    int ss[55], sp = 0;
    do
        ss[++sp] = x % 10;
    while (x /= 10);
    while (sp)
        putchar(48 + ss[sp--]);
}

int dp[3][maxn];
int a[maxn];

int main() {
    f();
    int n;
    read(n);
    int k = 1e5;
    dp[0][k] = 1;
    LL c = 0, b = 0;

    for (int i = 0; i < n; i++) {
        read(a[i]);
        a[i] = -a[i];
        b += a[i];
    }
    sort(a, a + n);
    b = -b;
    for (int i = 0; i <= (n - 1) / 2; i++) {
        c += -a[i];
    }
    b -= c;
    printf("%lld\n", c * c + b * b);

#ifndef ONLINE_JUDGE
    cout << "运行时间:" << 1.0 * (clock() - prostart) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

