#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, a[N];
long long len1, len2;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    int l = 1, r = n;
    while(l <= r) {
        if(l == r) len2 += a[l++];
        else {
            len1 += a[l++];
            len2 += a[r--];
        }
    }
    long long ans = len1 * len1 + len2 * len2;
    printf("%lld\n", ans);
    return 0;
}