#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
ll a[100000];

int main()
{
    int n; scanf("%d", &n);
    ll x = 0, y = 0, tmp;
    for(int i = 1; i <= n; i ++)
        scanf("%I64d", &a[i]), y += a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n / 2; i ++)
        x += a[i], y -= a[i];
    printf("%I64d", x * x + y * y);
    return 0;
}
