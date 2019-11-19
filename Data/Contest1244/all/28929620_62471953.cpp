#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int read();

int n;
long long k;
int a[200005];
struct P {
    int x, sum;
} p[200005];
int cnt;

int main() {
    scanf("%d%I64d", &n, &k);
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        int j = i;
        p[++cnt].x = a[i];
        while (a[j + 1] == a[i]) j++;
        p[cnt].sum = j - i + 1;
        i = j;
    }

    int st = 1, en = cnt;
    while (st < en) {
        if (p[st].sum <= p[en].sum) {
            long long t = p[st + 1].x - p[st].x;
            if (k >= t * p[st].sum) {
                k -= t * p[st].sum, p[st + 1].sum += p[st].sum;
                st++;
            } else {
                p[st].x += k / p[st].sum;
                break;
            }
        } else {
            long long t = p[en].x - p[en - 1].x;
            if (k >= t * p[en].sum) {
                k -= t * p[en].sum, p[en - 1].sum += p[en].sum;
                en--;
            } else {
                p[en].x -= k / p[en].sum;
                break;
            }
        }
    }
    printf("%d\n", p[en].x - p[st].x);
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}