#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    ll minx = 0x3f3f3f3f;
    for (int i = 1 ; i <= n; ++ i){
        scanf("%d", &a[i]);
        sum += 1ll * a[i];
    }
    sort(a + 1, a + 1 + n);
    ll x = 0;
    for (int i = 1; i <= n / 2 ; ++ i){
        x += 1ll * a[i];
    }
    sum -= x;
    ll ans = sum * sum + x * x;
    printf("%I64d\n", ans);
    return 0;
}

