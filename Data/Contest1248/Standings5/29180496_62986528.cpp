#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n;
long long a[maxn];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

    sort(a, a + n);

    int mid = n >> 1;

    long long p = 0;
    for(int i = 0; i < mid; i++) p += a[i];
    long long q = 0;
    for(int i = mid; i < n; i++) q += a[i];

    printf("%lld\n", p * p + q * q);

    return 0;
}
