#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<stack>
#include<string>

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int inf = 2e9;
const long long onf = 1e18;
#define me(a, b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI 3.14159265358979323846
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n, m;
int head[maxn], tot;
int a[maxn];
struct node {
    int v, next, val, c;
} maps[maxn << 1];


void add_edge(int u, int v, int val, int c) {
    maps[tot] = node{v, head[u], val, c};
    head[u] = tot++;
}

void ins(int u, int v, int val, int c) {
    add_edge(u, v, val, c);
    add_edge(v, u, val, c);
}

void init() {
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    tot = 0;
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll sum1 = 0, sum2 = 0;
    for (int i = n; i >= 1; i--) {
        if (i > n / 2)
            sum1 += a[i];
        else
            sum2 += a[i];
    }
    printf("%lld\n", sum1 * sum1 + sum2 * sum2);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
#endif
    int t = 1, Case = 1;
    //cin >> t;
    while (t--) {
        //  printf("Case %d: ", Case++);
        work();
    }
    return 0;
}