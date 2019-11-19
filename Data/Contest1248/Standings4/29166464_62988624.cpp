#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 2 * N + 5;

int n, a[N];
ll sum;
int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d", a + i), sum += a[i];
    sort(a, a + n);
    ll hna = 0;
    for(int i = 0 ; i < n / 2 ; ++i)
        hna += a[i], sum -= a[i];
    printf("%lld\n", (hna * hna) + (sum * sum));
}